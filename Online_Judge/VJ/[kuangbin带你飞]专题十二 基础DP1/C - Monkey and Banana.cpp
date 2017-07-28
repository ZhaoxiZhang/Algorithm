#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
const int maxn = 35;
struct Node{
    int len,wid,hei;
}node[maxn*3];
 
bool cmp(struct Node x,struct Node y)
{
    if (x.len == y.len) return x.wid < y.wid;
    else    return x.len < y.len;
}
 
int main()
{
    int N,Case = 0;
    while (~scanf("%d",&N) && N)
    {
        int x,y,z,p = 0,res = 0;
        int dp[maxn*3];
        for (int i = 0;i < N;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            node[p].len = x>y?x:y;node[p].wid = x<y?x:y;node[p++].hei = z;
            node[p].len = x>z?x:z;node[p].wid = x<z?x:z;node[p++].hei = y;
            node[p].len = y>z?y:z;node[p].wid = y<z?y:z;node[p++].hei = x;
        }
        sort(node,node+p,cmp);
        for (int i = 0;i < p;i++)
        {
            dp[i] = node[i].hei;
            for (int j = 0;j < i;j++)
            {
                if (node[i].len > node[j].len && node[i].wid > node[j].wid && dp[i] < dp[j] + node[i].hei)
                {
                    dp[i] = dp[j] + node[i].hei;
                }
            }
            res = max(res,dp[i]);
        }
        printf("Case %d: maximum height = %d\n",++Case,res);
    }
    return 0;
}

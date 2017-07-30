#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
struct Node
{
    int x,y;
}node[maxn],gun;
bool flag[maxn];

int main()
{
    int n,res = 0;
    memset(flag,false,sizeof(flag));
    scanf("%d%d%d",&n,&gun.x,&gun.y);
    for (int i = 0;i < n;i++)
    {
        scanf("%d%d",&node[i].x,&node[i].y);
    }
    for (int i = 0;i < n;i++)
    {
        if (!flag[i])
        {
            res++,flag[i] = true;
            for (int j = i + 1;j < n;j++)
            {
                if (flag[j])    continue;
                if ((node[j].y - gun.y)*(node[i].x - gun.x) == (node[i].y - gun.y)*(node[j].x - gun.x))
                {
                    flag[j] = true;
                }
            }
        }
    }
    printf("%d\n",res);
    return 0;
}
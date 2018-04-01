#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;
const int maxn = 200005;
int num[maxn];

int main()
{
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,k,tmp;
        scanf("%d%d%d",&n,&m,&k);
        for (int i = 0;i < n;i++)
        {
            scanf("%d",&tmp);
            num[i] = tmp >= m?1:0;
        }
        int s = 0,t = 0;
        LL res = 0,sum = 0;
        for (;;)
        {
            while (t < n && sum < k)
            {
                sum += num[t++];
            }
            if (sum < k)    break;
            res += n - t + 1;
            sum -= num[s++];
        }
        printf("%I64d\n",res);
    }
    return 0;
}

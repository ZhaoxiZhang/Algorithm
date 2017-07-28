#include<stdio.h>
typedef long long LL;

int gcd(LL m,LL n)
{
    int  tmp;
    if (m < n)
    {
        tmp = m;
        m = n;
        n = tmp;
    }
    if (m % n == 0)
    {
        return n;
    }
    else
    {
        return gcd(n,m%n);
    }
}

int main()
{
    int T,N,M,i;
    scanf("%d",&T);
    while(T--)
    {
        int ans[10005];
        scanf("%d%d",&N,&M);

        for (i = 0; i < N; i++)
        {
            scanf("%d",&ans[i]);
        }

        while (M--)
        {
            int left,right;

            scanf("%d%d",&left,&right);
            int tmp = ans[left];
            for (i = left + 1; i <= right; i++)
            {
                tmp = gcd(ans[i],tmp);
            }

            printf("%d\n",tmp);
        }
    }
    
    return 0;
}


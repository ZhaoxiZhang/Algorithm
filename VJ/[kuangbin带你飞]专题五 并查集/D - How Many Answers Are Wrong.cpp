#include<stdio.h>
#include<string.h> 
const int maxn = 200005;
int fa[maxn],sum[maxn];

int find(int x)
{
    if (fa[x] != x)
    {
        int tmp = fa[x];
        fa[x] = find(fa[x]);
        sum[x] += sum[tmp];
    }
    return fa[x];
}

int main()
{
    int N,M;
    while (~scanf("%d%d",&N,&M))
    {
    	int res = 0;
        for (int i = 1; i <= N; i++)	fa[i] = i,sum[i] = 0;
        while (M--)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            a--;
            int pa = find(a),pb = find(b);
            if (pa == pb)
            {
                if (sum[b] - sum[a] != v)	res++;
            }
            else
            {
                fa[pb] = pa;
                sum[pb] = -sum[b] + v + sum[a];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

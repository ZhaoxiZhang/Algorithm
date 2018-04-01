#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const double INF = 0x3f3f3f3f;

struct Node
{
    double val;
    int id;
};

bool cmp(Node x,Node y)
{
	return x.val > y.val;
}

int main()
{
    int N,K;
    while (~scanf("%d%d",&N,&K))
    {
        double tmp,sum = 0,smin = INF,smax = 0,pmin = INF,pmax = 0,sum1 = 0,sum2 = 0;
        int opt;
        Node stool[1005],pencil[1005];
        memset(stool,0,sizeof(stool));
        memset(pencil,0,sizeof(pencil));
        int s = 0, p = 0;
        for (int i = 1; i <= N; i++)
        {
            scanf("%lf %d",&tmp,&opt);
            if (opt == 1)
            {
                stool[s].id = i;
                stool[s++].val = tmp;
                smin = min(smin,tmp);
                smax = max(smax,tmp);
                sum1 += tmp;
            }
            else
            {
                pencil[p].id = i;
                pencil[p++].val = tmp;
                pmax = max(pmax,tmp);
                pmin = min(pmin,tmp);
                sum2 += tmp;
            }
        }
        if (s >= K)
        {
            sort(stool,stool+s,cmp);
			for (int i = 0; i < K - 1; i++)
            {
                sum += stool[i].val;
            }
            sum *= 0.5;
            for (int i = K - 1; i < s; i++)
            {
                sum += stool[i].val;
            }
            sum += sum2;
            double minn  = min(pmin,smin);
            sum -= minn*0.5;
            printf("%.1lf\n",sum);
            for (int i = 0; i < K - 1; i++)
            {
                printf("1 %d\n",stool[i].id);
            }
            printf("%d",p+s-K+1);
            for (int i = K - 1; i < s; i++)
            {
                printf(" %d",stool[i].id);
            }
            for (int i = 0; i < p; i++)
            {
                printf(" %d",pencil[i].id);
            }
            printf("\n");
        }
        else
        {
            sum1 *= 0.5;
            sum += sum1 + sum2;
            printf("%.1lf\n",sum);
            for (int i = 0; i < s; i++)
            {
                printf("1 %d\n",stool[i].id);
            }
            for (int i = 0 ; i < K - s - 1; i++)
            {
                printf("1 %d\n",pencil[i].id);
            }
            printf("%d",p-(K-s-1));
            for (int i = K - s - 1; i < p; i++)
        	{
            	printf(" %d",pencil[i].id);
            }
            printf("\n");
        }
    }
    return 0;
}


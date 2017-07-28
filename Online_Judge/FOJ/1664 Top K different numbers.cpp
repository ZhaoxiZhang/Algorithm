#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int N,K;
    while (~scanf("%d%d",&N,&K))
    {
        int ans[10005],arr[10005];
        int i,j;
        for (i = 0; i < N; i++)
        {
            scanf("%d",&ans[i]);
        }
        sort(ans,ans + N);
        for (i = 0,j = 0; i < N; j++)
        {
            while (ans[i] == ans[i + 1])
            {
                i++;
            }
            arr[j] = ans[i++];
        }
        if (j < K)
        {
            printf("-1\n");
        }
        else
        {
           	printf("%d",arr[j - K]);
            for (i = j - K + 1;i < j;i++)
            {
            	printf(" %d",arr[i]);
            }
            printf("\n");
        }
    }
    return 0;
}


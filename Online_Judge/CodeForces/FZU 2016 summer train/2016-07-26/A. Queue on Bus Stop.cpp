#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int N,M;
    while (~scanf("%d%d",&N,&M))
    {
        int sum1 = 0,sum = 0,cnt = 0,ans[105] = {0};
        for (int i = 0; i < N; i++)
        {
            scanf("%d",&ans[i]);
            sum1 += ans[i];
        }
        if (sum1 < M)
        {
            printf("1\n");
        }
        else
        {
        	for (int i = 0;i < N;i++)
        	{
        		
				sum += ans[i];
        		if (sum == M)
        		{
        			cnt++;
        			sum = 0;
        		}
        		if (sum > M)
        		{
        			cnt++;
        			sum = ans[i];
        		}
        		if (sum == M)
        		{
        			cnt++;
        			sum = 0;
        		}
        		if (i == N - 1 && sum < M && sum)
				{
					cnt++;
				} 
        	}
            printf("%d\n",cnt);
        }
    }
    return 0;
}


#include<stdio.h>
int main()
{
	int N,i,sum;
	int ans[105]={0};
	while(scanf("%d",&N)!=EOF)
	{
		if(!N) return 0;
		sum=0;
		for(i=1;i<N+1;i++)
		{
			scanf("%d",&ans[i]);
		}
		for(i=0;i<N;i++)
		{
			if(ans[i+1]>ans[i])
			{
				sum+=(ans[i+1]-ans[i])*6;
			}
			else
			{
				sum+=(ans[i]-ans[i+1])*4;
			}
		}
		printf("%d\n",sum+5*N);
	}
} 

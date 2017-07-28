#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int N,M;
	bool flag = false;
	while (~scanf("%d%d",&N,&M) && N && M)
	{
		if (flag)
		{
			printf("\n");
		}
		flag = true;
		for (int i = 1;i <= N;i++)
		{
			if (i > M) break;
			int sum = 2*M+i*i-i;
			if (sum > N*N)
				break; 
			int tmp = sqrt(sum);
			if (tmp*(tmp+1) == sum || (tmp - 1)*tmp == sum || (tmp+1)*(tmp+2))
			{
				if (tmp*(tmp+1) == sum)
				{
					if (i < tmp)
						printf("[%d,%d]\n",i,tmp);
					else
						printf("[%d,%d]\n",tmp,i);
				}
				else if ((tmp-1)*tmp == sum)
				{
					if (i < tmp - 1)
					{
						printf("[%d,%d]\n",i,tmp-1);
					}
					else
					{
						printf("[%d,%d]\n",tmp - 1,i);
					}
				}
				else if ((tmp+1)*(tmp+2) == sum)
				{
					if (i < tmp+1)
						printf("[%d,%d]\n",i,tmp=1);
					else
						printf("[%d,%d]\n",tmp+1,i);
				}
			}
		}
	}
	return 0;
} 

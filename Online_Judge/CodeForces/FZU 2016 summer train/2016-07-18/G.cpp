#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int ans[10] = {0};
		int tmp,sum = 0;
		bool flag = false;
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&tmp);
			ans[tmp]++;
			sum += tmp;
		} 
		if (ans[0] == 0)
		{
			printf("-1\n");
		}
		else
		{
			flag = true;
			if (sum % 3 == 1)
			{
				if (ans[1] + ans[4] + ans[7])
				{
					for (int i = 1;i <= 7;i += 3)
					{
						if (ans[i])
						{
							ans[i]--;
							break;
						}
					}
				}
				else if (ans[2] + ans[5] + ans[8] >= 2)
				{
					for (int i = 2,j = 1;i <= 8;i+=3)
					{
						while (ans[i] && j <= 2)
						{
							ans[i]--;
							j++;
						}
					}
				}
			} 
			else if (sum % 3 == 2)
			{
				if (ans[2] + ans[5] + ans[8])
				{
					for (int i = 2;i <= 8;i += 3)
					{
						if (ans[i])
						{
							ans[i]--;
							break;
						}
					}
				}
				else if (ans[1] + ans[4] + ans[7] >= 2)
				{
					for (int i = 1,j = 1;i <= 7;i += 3)
					{
						while (ans[i] && j <= 2)
						{
							ans[i]--;
							j++;
						}
					}
				}
			}
		}
		
		if (flag)
		{
			if (ans[1] + ans[2] + ans[3] + ans[4] + ans[5] + ans[6] + ans[7] + ans[8] + ans[9])
			{
				for (int i = 9;i >= 0;i--)
				{
					while (ans[i]--)
					{
						printf("%d",i);
					}
				}
			}
			else
			{
				printf("0");
			}
			printf("\n");
		}
	}
	return 0;
}

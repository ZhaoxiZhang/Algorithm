#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		map<int ,int>vote;
		int N,winner,max = 0;
		bool flag;
		scanf("%d",&N);
		for (int i = 0;i < N;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			vote[tmp]++;
			if (vote[tmp] > max)
			{
				winner = tmp;
				max = vote[tmp];
				flag = true;
			}
			else if (max == vote[tmp])
			{
				flag = false;
			}
		}
		if (flag)
		{
			printf("%d\n",winner);
		}
		else
		{
			printf("Nobody\n");
		}
	}
	return 0;
} 

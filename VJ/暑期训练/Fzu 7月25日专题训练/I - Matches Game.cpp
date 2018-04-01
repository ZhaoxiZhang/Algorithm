#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int tmp,res = 0;
		while (N--)
		{
			scanf("%d",&tmp);
			res ^= tmp; 
		}
		if (res == 0)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
	return 0;
} 

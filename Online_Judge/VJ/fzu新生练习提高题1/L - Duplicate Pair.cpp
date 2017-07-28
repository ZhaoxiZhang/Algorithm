#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int N,tmp;
	while (~scanf("%d",&N))
	{
		char arr[1000005];
		memset(arr,0,sizeof(arr));
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&tmp);
			if (arr[tmp])
			{
				printf("%d\n",tmp);
				break;
			}
			arr[tmp] = 1;
		}
	}
}

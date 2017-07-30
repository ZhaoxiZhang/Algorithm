#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set> 
using namespace std;

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int tmp,cnt;
		set<int>s;
		scanf("%d",&cnt);
		while (cnt--)
		{
			scanf("%d",&tmp);
			s.insert(tmp);
		}
		scanf("%d",&cnt);
		while (cnt--)
		{
			scanf("%d",&tmp);
			s.insert(tmp);
		}
		int len = s.size();
		if (len == N)
		{
			printf("I become the guy.\n");
		}
		else
		{
			printf("Oh, my keyboard!\n");
		}
	}
	return 0;
}

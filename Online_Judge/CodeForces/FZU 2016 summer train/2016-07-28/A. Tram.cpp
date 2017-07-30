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
		int maxx = 0,res = 0;
		int a,b;
		while (N--)
		{
			scanf("%d%d",&a,&b);
			res -= a;
			res += b;
			maxx = max(res,maxx);
		}
		printf("%d\n",maxx);
	}
	return 0;
}

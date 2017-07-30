#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;

int main()
{
	LL N;
	while (~scanf("%I64d",&N))
	{
		LL ans[105] = {0};
		LL res = 0;
		for (int i = 1;i <= N;i++)
		{
			scanf("%I64d",&ans[i]);
			res += (ans[i] - 1)*i + 1;
		}
		printf("%I64d\n",res);
	}
	return 0;
}

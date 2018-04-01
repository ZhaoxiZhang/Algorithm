#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef __int64 LL;
int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		LL tmp,res = 0;
		map<LL,LL>mp;
		for (int i = 0;i < N;i++)
		{
			scanf("%I64d",&tmp);
			for (int j = 1;j < 32;j++)
			{
				if (mp.find((1<<j)-tmp) != mp.end())
				{
					res += mp[(1<<j)-tmp];
				}
			}
			mp[tmp]++;
		}
		printf("%I64d\n",res);
	}
	return 0;
}

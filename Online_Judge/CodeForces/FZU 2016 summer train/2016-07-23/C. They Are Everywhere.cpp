#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	int N;
	char str[100005];
	set<char>all;
	memset(str,0,sizeof(str));
	scanf("%d",&N);
	scanf("%s",str);
	for (int i = 0;i < N;i++)
	{
		all.insert(str[i]);
	}
	int n = all.size();
	int s = 0,t = 0,num = 0;
	map<char,int>count;
	int res = N;
	for (;;)
	{
		while (t < N && num < n)
		{
			if (count[str[t++]]++ == 0)
			{
				num++;
			}
		}
		if (num < n)
			break;
		res = min(res,t-s);
		if (--count[str[s++]] == 0)
		{
			num--;
		}
	}
	printf("%d\n",res);
	return 0;
}

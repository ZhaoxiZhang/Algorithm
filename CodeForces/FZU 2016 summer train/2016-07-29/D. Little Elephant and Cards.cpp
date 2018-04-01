#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef __int64 LL;

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		LL x,y;
		map<LL,LL>m1,m2;
		map<LL,LL>::iterator itt;
		set<LL>s;
		set<LL>::iterator it;
		for (int i = 0;i < N;i++)
		{
			scanf("%I64d%I64d",&x,&y);
			m1[x]++;
			if (x != y)
			{
				m2[y]++;
			}
			s.insert(x);
			s.insert(y);
		}
		LL res = INF;
		LL tmp = (N+1)/2;
		for (it = s.begin();it != s.end();it++)
		{
			x = *it;
			if (m1[x] + m2[x] >= tmp)
			{
				res = min(res,max(0LL,tmp - m1[x]));
			}
		}
		if(res == INF)
		{
			res = -1;
		}
		printf("%I64d\n",res);
	}
	return 0;
}


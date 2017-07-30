#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Can{
	__int64 vote;
	__int64 city;
	__int64 id;
};

bool cmp(struct Can xx,struct Can yy)
{
	if (xx.vote == yy.vote && xx.city == yy.city)
	{
		return xx.id < yy.id;
	}
	else if (xx.vote == yy.vote)
	{
		return xx.city > yy.city;
	}
	else
	{
		return xx.vote > yy.vote;
	}
}

int main()
{
	__int64 N,M;
	struct Can can[1005];
	memset(can,0,sizeof(can));
	scanf("%I64d%I64d",&N,&M);
	while (M--)
	{
		__int64 tmp,cnt,max = 0;
		for (__int64 i = 1;i <= N;i++)
		{
			can[i].id = i;
			scanf("%I64d",&tmp);
			if (tmp)
			{
				can[i].city++;
			}
			if (tmp > max)
			{
				cnt = i;
				max = tmp;
			}
		} 
		can[cnt].vote++;
	}
	sort(can+1,can + N + 1,cmp);
	printf("%I64d\n",can[1].id);
	return 0;
}

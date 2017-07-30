#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;

int main()
{
	LL N,M;
	while (~scanf("%I64d%I64d",&N,&M))
	{
		LL sum = N*N; 
		LL x,y,xcnt = 0,ycnt = 0;
		bool r[100005],c[100005];
		memset(r,false,sizeof(r));
		memset(c,false,sizeof(c));
		bool first = true;
		while (M--)
		{
			scanf("%I64d%I64d",&x,&y);
			if (!c[y])
			{
				sum -= (N - xcnt);
				c[y] = true;
				ycnt++;
			}
			if (!r[x])
			{
				sum -= (N - ycnt);
				r[x] = true;
				xcnt++;
			} 
			first?printf("%I64d",sum):printf(" %I64d",sum);
			first = false;
		}
		printf("\n");
	}
	return 0;
}


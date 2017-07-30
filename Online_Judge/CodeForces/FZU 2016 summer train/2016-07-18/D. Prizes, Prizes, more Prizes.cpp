#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef __int64 LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

struct Node
{
	LL val,cnt;
};

int main()
{
	LL N;
	LL sum = 0,minn = INF;
	LL ans[55] = {0};
	Node food[10];
	memset(food,0,sizeof(food));
	scanf("%I64d",&N);
	for(int i = 0;i < N;i++)
	{
		scanf("%I64d",&ans[i]);
	}
	for (int i = 0;i < 5;i++)
	{
		scanf("%I64d",&food[i].val);
		if(food[i].val < minn)
		{
			minn = food[i].val;
		}
	}
	for (int i = 0;i < N;i++)
	{
		sum += ans[i];
		while (sum >= minn)
		{
			for (int i = 4;i >= 0;i--)
			{
				if (sum >= food[i].val)
				{
					LL tmp = sum / food[i].val;
					sum -= tmp*food[i].val;
					food[i].cnt += tmp;
				}
			}
		}
	}
	bool first = true;
	for (int i = 0;i < 5;i++)
	{
		first?printf("%I64d",food[i].cnt):printf(" %I64d",food[i].cnt);
		first = false;
	}
	printf("\n%I64d\n",sum);
	return 0;
}

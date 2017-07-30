#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;
struct node{
	LL a,b;
}; 

node Node[1005];

bool cmp(node x,node y)
{
	if (x.b != y.b)
	{
		return x.b > y.b;
	}
	else
	{
		return x.a > y.a;
	}
}

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		memset(Node,0, sizeof(Node));
		for (int i = 1;i <= N;i++)
		{
			scanf("%I64d%I64d",&Node[i].a,&Node[i].b);
		}
		sort(Node+1,Node+N+1,cmp);
		LL sum = Node[1].a;
		LL val = Node[1].b;
		int i = 2;
		if (val != 0)
		{
			while (val != 0 && i <= N)
			{
				val--;
				sum += Node[i].a;
				val += Node[i].b;
				i++;
			}
		}
		printf("%I64d\n",sum);
	}
	return 0;
}

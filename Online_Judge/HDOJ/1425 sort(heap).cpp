#include<stdio.h>
#include<string.h>
const int maxn = 1000005;
int heap[maxn],sz = 0;

void push(int x)
{
	int i = sz++;
	while (i > 0)
	{
		int p = (i - 1)/2;
		if (heap[p] >= x)	break;
		heap[i] = heap[p];
		i = p;
	}
	heap[i] = x;
}

int pop()
{
	int ret = heap[0];
	int x = heap[--sz];
	int i = 0;
	while (i*2+1<sz)
	{
		int a = i*2+1,b = i*2+2;
		if (b < sz && heap[b]>heap[a])	a = b;
		if (heap[a] <= x)	break;
		heap[i] = heap[a];
		i = a;
	}
	heap[i] = x;
	return ret;
}

int main()
{
	int n,m,tmp;
	while (~scanf("%d%d",&n,&m))
	{
		sz = 0;
		memset(heap,0,sizeof(heap));
		for (int i = 0;i < n;i++)	scanf("%d",&tmp),push(tmp);
		for (int i = 1;i < m;i++)	printf("%d ",pop());
		printf("%d\n",pop());
	}
	return 0;
}

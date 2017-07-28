#include<stdio.h>
#include<string.h>
const int maxn = 1000005;
int a[maxn],q[maxn];
int n,k;

void Monotonequeue(int opt)
{
	memset(q,0,sizeof(q));
	int head = 1,tail = 0;
	for (int i = 1;i <= n;i++)
	{
		while (head <= tail && ((!opt && a[i] <= a[q[tail]]) || (opt && a[i] >= a[q[tail]])))	tail--;
		q[++tail] = i;
		while (head <= tail && q[tail] - q[head] >= k)	head++;
		if (i == k)	printf("%d",a[q[head]]);
		if (i > k)	printf(" %d",a[q[head]]);
	}
	printf("\n");
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++)	scanf("%d",&a[i]);
	Monotonequeue(0);
	Monotonequeue(1);
	return 0;
} 

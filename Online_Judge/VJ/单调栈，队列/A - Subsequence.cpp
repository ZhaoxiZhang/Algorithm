#include<stdio.h>
#include<string.h>
const int maxn = 100005;
int a[maxn],q1[maxn],q2[maxn];

int main()
{
	int n,m,k;
	while (~scanf("%d%d%d",&n,&m,&k))
	{
		int res = 0,pos = 0;
		memset(a,0,sizeof(a));
		memset(q1,0,sizeof(q1));
		memset(q2,0,sizeof(q2));
		for (int i = 1;i <= n;i++)	scanf("%d",&a[i]);
		int head1 = 1,head2 = 1,tail1 = 0,tail2 = 0;
		for (int i = 1;i <= n;i++)
		{
			while (head1 <= tail1 && a[i] <= a[q1[tail1]])	tail1--;  //队头元素最小 
			q1[++tail1] = i;
			while (head2 <= tail2 && a[i] >= a[q2[tail2]])	tail2--;  //队头元素最大 
			q2[++tail2] = i;
			while (head1 <= tail1 && head2 <= tail2 && a[q2[head2]] - a[q1[head1]] > k)
			{
				if (q1[head1]<q2[head2])	pos = q1[head1++];
				else	pos = q2[head2++];
			}
			if (head1 <= tail1 && head2 <= tail2 && a[q2[head2]] - a[q1[head1]] >= m)	res = res>(i-pos)?res:(i-pos);
			
		}
		printf("%d\n",res);
	}
	return 0;
}

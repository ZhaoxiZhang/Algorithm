#include<stdio.h>
#include<string.h>
typedef __int64 LL;
const int maxn = 1000005;
LL a[maxn],stack[maxn] = {0},left[maxn] = {0},sum[maxn] = {0};

int main()
{
	LL N,L = 0,R = 0,res = -1,tmp = 0;
	scanf("%I64d",&N);
	for (int i = 1;i <= N;i++)	scanf("%I64d",&a[i]),sum[i] = a[i] + sum[i-1];
	a[++N] = -1;
	int top = 0;
	for (int i = 1;i <= N;i++)
	{
		if (!top || a[i] > a[stack[top-1]])
		{
			stack[top++] = i;
			left[i] = i;
			continue;
		}
		
		if (a[i] == a[stack[top-1]])	continue;
		
		while (top > 0 && a[i] < a[stack[top-1]])
		{
			top--;
			tmp = a[stack[top]]*(sum[i-1] - sum[left[stack[top]] - 1]);
			if (tmp > res)	res = tmp,L = left[stack[top]],R = i-1;
		}
		tmp = stack[top];
		stack[top++] = i;
		left[i] = left[tmp];
	}
	printf("%I64d\n%I64d %I64d\n",res,L,R);
	return 0;
}

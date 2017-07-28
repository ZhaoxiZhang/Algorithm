#include<stdio.h>
#include<string.h>
typedef __int64 LL;
const int maxn = 100005;
LL a[maxn],stack[maxn],left[maxn];

int main()
{
	int N;
	while (~scanf("%d",&N) && N)
	{
		LL res = 0,tmp;
		memset(stack,0,sizeof(stack));
		memset(left,0,sizeof(left));
		for (int i = 1;i <= N;i++)	scanf("%I64d",&a[i]);
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
				tmp = a[stack[top]]*((i-1)- (left[stack[top]]-1));
				res = res<tmp?tmp:res; 
			}
			tmp = stack[top];
			stack[top++] = i;
			left[i] = left[tmp];
		}
		printf("%I64d\n",res);
	}
	return 0;
}

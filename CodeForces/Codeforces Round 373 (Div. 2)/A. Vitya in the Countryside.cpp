#include<cstdio>
using namespace std;
const int maxn = 100;

int main()
{
	int N,a[maxn];
	scanf("%d",&N);
	for (int i = 0;i < N;i++)	scanf("%d",&a[i]);
	if (N == 1)
	{
		if (a[0] == 15)	printf("DOWN\n");
		else if (a[0] == 0)	printf("UP\n");
		else	printf("-1\n");
	}
	else
	{
		if (a[N-1] == 0)	printf("UP\n");
		else if (a[N-1] == 15)	printf("DOWN\n");
		else if (a[N-2] > a[N-1])	printf("DOWN\n");
		else if (a[N-2] < a[N-1])	printf("UP\n");
	}
	return 0;
}

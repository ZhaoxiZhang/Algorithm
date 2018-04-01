#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e6+5;
int a[maxn];

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		for (int i = 0;i < N;i++)	scanf("%d",&a[i]);
		sort(a,a+N);
		printf("%d\n",a[(N+1)/2]);
	}
	return 0;
}

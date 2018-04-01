#include<cstdio>
using namespace std;
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		int sum = (1 + n) * n / 2;
		int tmp;
		n -= 1;
		while (n--)
		{
			scanf("%d",&tmp);
			sum -= tmp; 
		}
		printf("%d\n",sum);
	}
	return 0;
}

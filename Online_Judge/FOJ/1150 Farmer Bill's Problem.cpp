#include<cstdio>
using namespace std;

int main()
{
	int n,k;
	while (~scanf("%d%d",&n,&k))
	{
		int dif = n,sum = n;
		while (dif >= k)
		{
			sum += dif /k;
			dif = dif/k + dif % k;
			
		}
		printf("%d\n",sum);
	}
}

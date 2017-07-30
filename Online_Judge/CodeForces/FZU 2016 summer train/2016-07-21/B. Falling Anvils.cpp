#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		double a,b;
		scanf("%lf%lf",&a,&b);
		if (b == 0)
		{
			printf("1\n");
		}
		else
		{
			if (a > 4*b)
			{
				printf("%.10lf\n",1 - b/a);
			}
			else
			{
				printf("%.10lf\n",0.5+a / (16*b));
			}
		}
	}
	return 0;
}

#include<stdio.h>
#include<math.h>
#define PI 3.1415926

int main()
{
	int K;
	scanf("%d",&K);
	while (K--)
	{
		int V;
		double r,V1;
		scanf("%d",&V);
		for (r = 0.01;PI*r*r < 500; r += 0.01)
		{
			V1 = 500*r - PI*r*r*r;
			if (V1 > V)
			{
				break;
			}
		}
		if (PI*r*r >= 500)
		{
			printf("NO\n");
		}
		else
		{
			printf("%.1lf\n",r);
		}
	}
	return 0;
} 

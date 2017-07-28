#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		double x1,y1,r1,x2,y2,r2;
		scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2);
		double len1,len2,len3,min,max;
		max = r1 >= r2 ? r1 : r2;
		min = r1 < r2 ? r1 : r2;
		len1 = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		len2 = r1 + r2;
		len3 = max - min;
			
		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			printf("-1\n");
		}
		else if (len2 < len1)
		{
			printf("4\n");
		}
		else if (len2 > len1 && len1 > len3)
		{
			printf("2\n");
		}
		else if (len2 == len1)
		{
			printf("3\n");
		}
		else if (len3 == len1)
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}

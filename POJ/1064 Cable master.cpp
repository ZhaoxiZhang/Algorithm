#include<iostream>
#include<cstdio>
#include<cmath>
#define EPS 1e-6
const int INF = 100000;
using namespace std;
int N,K;
double ans[10005];

bool binary(double x)
{
	int sum = 0;
	for (int i = 0;i < N;i++)
	{
		sum += (int)(ans[i] / x);
	}
	return sum >= K;
}

int main()
{
	while (scanf("%d%d",&N,&K) != EOF)
	{
		for (int i = 0;i < N;i++)
		{
			scanf("%lf",&ans[i]);
		}
		
		double left = 0,right = INF,mid;
		
		while (right - left > EPS)
		{
			mid = (left + right)/2;
			if (binary(mid))
			{
				left = mid;
			}
			else
			{
				right = mid;
			}
		}
		
		/*if (mid < 1)
		{
			printf("0.00\n");
		}
		else
		{
			printf("%.2lf\n",mid);
		}*/
		
		printf("%.2f\n",floor(right*100)/100); //·ÀÖ¹ËÄÉáÎåÈë 
	}
	
	return 0;
}

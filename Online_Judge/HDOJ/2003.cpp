#include<stdio.h>
#include<math.h>
int main()
{
	double num,sum;
	while(scanf("%lf",&num)!=EOF){
		sum=fabs(num);
		printf("%.2lf\n",sum);
	}
	return 0;
} 

#include<stdio.h>
#include<math.h>
int main()
{
	double n,m,i,temp,sum;
	while(scanf("%lf%lf",&n,&m)!=EOF){
		sum=n;
		temp=n;
		for(i=0;i<m-1;i++){
			temp=sqrt(temp);
			sum+=temp;
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}

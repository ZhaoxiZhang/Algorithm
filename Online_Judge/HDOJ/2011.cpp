#include<stdio.h>
int main()
{
	int m,num,i,j;
	double sign,sum,res;
	scanf("%d",&m);
		for(i=0;i<m;i++){
			sign=-1;sum=0;
			scanf("%d",&num);
			for(j=1;j<num+1;j++){
				sign=-sign;
				res=sign/j;
				sum+=res;
			}
			printf("%.2lf\n",sum);
		}
	return 0;
}

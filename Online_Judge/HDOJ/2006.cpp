#include<stdio.h>
int main()
{
	int n,i,sum,num;
	while(scanf("%d",&n)!=EOF){
		sum=1;
		for(i=0;i<n;i++){
			scanf("%d",&num);
			if(num%2!=0){
				sum*=num;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
} 

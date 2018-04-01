#include<stdio.h>
int main()
{
	int min,max,sum1,sum2,i,temp;
	while(scanf("%d%d",&min,&max)!=EOF){
		if(min>max){
			temp=min;
			min=max;
			max=temp;
		}
		sum1=0;sum2=0;
		for(i=min;i<max+1;i++){
			if(i%2==0){
				sum1+=i*i;
			} 
			else{
				sum2+=i*i*i;
			}
		}
		printf("%d %d\n",sum1,sum2);
	}
	return 0;
}

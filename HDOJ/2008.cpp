#include<stdio.h>
int main()
{
	int n,i,count1,count2,count3;
	float num;
	while(scanf("%d",&n)!=EOF){
		count1=0;count2=0;count3=0;
		if(n==0)
		continue;
		else{
		for(i=0;i<n;i++){
			scanf("%f",&num);
			if(num<0)
			   count1++;
			else if(num==0)
			   count2++;
			else if(num>0)
			   count3++;
			   }
			   printf("%d %d %d\n",count1,count2,count3);
		}
	}
	return 0;
}

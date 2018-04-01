#include<stdio.h>
int main()
{
	int n,i,temp;
	int arr[105];
	while(scanf("%d",&n)!=EOF){
		if(n==0)continue;
		else{
			for(i=0;i<n;i++){
				scanf("%d",&arr[i]);
			}
			temp=arr[0];
			for(i=1;i<n;i++){
				if(arr[i]<temp)
				   temp=arr[i];
			}
			for(i=1;i<n;i++){
				if(arr[i]==temp){
					arr[i]=arr[0];
					arr[0]=temp;
					break;
				}
			}
			printf("%d",arr[0]);
			for(i=1;i<n;i++){
				printf(" %d",arr[i]);
			}
			printf("\n");
		}
	}
	return 0;
}

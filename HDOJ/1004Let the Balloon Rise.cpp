#include<stdio.h>
#include<string.h>
int main()
{
	int N,i,j,t,max=0;
	char ans[1000][16];
	while(scanf("%d",&N)!=EOF){
		int num[1000]={0};
		t=0;
		if(!N)return 0;
		scanf("%s",ans[0]);
		for(i=1;i<N;i++){
			scanf("%s",ans[i]);
			for(j=0;j<i;j++){
				if(strcmp(ans[i],ans[j])==0){
					num[i]+=1;
				}
			}
		}
		for(i=0;i<N;i++){
			if(num[i]>max){
				max=num[i];
				t=i;
			}
		}
		printf("%s\n",ans[t]);
	}
	return 0;
} 

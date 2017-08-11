#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,d,h;
	scanf("%d%d%d",&n,&d,&h);
	if (d > 2*h || h > d || d > n - 1 || (d == 1 && n > 2)) 	printf("-1\n");
	else{
		for (int i = 1;i <= h;i++){
			printf("%d %d\n",i,i + 1);
		}
		for (int i = 1;i <= d - h;i++){
			i == 1 ? printf("1 %d\n",h + i + 1):printf("%d %d\n",h + i,h + i + 1);
		}
		if (d == h){
			for (int i = d + 2;i <= n;i++){
				printf("2 %d\n",i);
			}
		}
		else{
			for (int i = d + 2;i <= n;i++){
				printf("1 %d\n",i);
			}
		}
	}
	return 0;
}

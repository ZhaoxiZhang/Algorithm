#include <stdio.h>
#include <string.h>

int main(){
	char str1[1001], str2[1001];
	int t, i, len_str1, len_str2, len_max, num = 1, k;
	scanf("%d", &t);
	getchar();
	while(t--){
		int a[1001] = {0}, b[1001] = {0}, c[1001] = {0};
		scanf("%s", str1);
		len_str1 = strlen(str1);
		for(i = 0; i <= len_str1 - 1; ++i)
			a[i] = str1[len_str1 - 1 - i] - '0';
		scanf("%s",str2);
		len_str2 =  strlen(str2);
		for(i = 0; i <= len_str2 - 1; ++i)
			b[i] = str2[len_str2 - 1 - i] - '0';
		if(len_str1 > len_str2)
			len_max = len_str1;
		else
			len_max = len_str2;
		k = 0;
		for(i = 0; i <= len_max - 1; ++i){
			c[i] = (a[i] + b[i] + k) % 10;
			k = (a[i] + b[i] + k) / 10;
		}
		if(k != 0)
		c[len_max] = 1;
		printf("Case %d:\n", num);
		num++;
		printf("%s + %s = ", str1, str2);
		if(c[len_max] == 1)
			printf("1");
		for(i = len_max - 1; i >= 0; --i){
			printf("%d", c[i]);
		}
		printf("\n");
		if(t >= 1)
			printf("\n");
	}
	return 0;

}

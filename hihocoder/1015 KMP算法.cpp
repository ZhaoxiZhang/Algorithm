#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int nxt[maxn];
char a[maxn], b[maxn];

void getNxt(char *pattern, int len){
	nxt[0] = -1;
	int i = 0, k = -1;
	while (i < len){
		if (k == -1 || pattern[k] == pattern[i]){
			k++;
			i++;
			//优化nxt数组 
			if (pattern[k] != pattern[i])	nxt[i] = k;
			else	nxt[i] = nxt[k];
		}else{
			k = nxt[k];
		}
	}
}

int kmp(char *origin, int len1, char *pattern, int len2){
	int i = 0, k = 0, res = 0;
	while (i < len1){
		if (k == -1 || pattern[k] == origin[i])	{
			i++;
			k++;
		}else	k = nxt[k];
		if (k == len2){
			res++, k = nxt[k];
		}	
	}
	return res;
} 

int main(){
	int N;
	scanf("%d", &N);
	while (N--){
		memset(nxt, 0, sizeof(nxt));
		scanf("%s %s", a, b);
		getNxt(a, strlen(a));
		printf("%d\n", kmp(b, strlen(b), a, strlen(a)));
	}	
	return 0;
}

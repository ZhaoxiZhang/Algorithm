#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;
char str[maxn];
int pos,height;

void dfs(int depth){
	pos++;
	height = max(depth,height);
	if (str[pos] == '\0')	return;
	if (str[pos] == 'l')	return;
	if (str[pos] == 'n'){
		dfs(depth + 1);  //left
		dfs(depth + 1);  //right;
	}
}


int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		memset(str,0,sizeof(str));
		height = 0,pos = -1;
		scanf("%s",str);
		dfs(0);
		cout << height << endl;
	}
	return 0;
}

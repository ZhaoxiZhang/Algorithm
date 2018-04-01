#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int color[maxn];
vector<int>itv[maxn];
bool ok;
int curr_color;

void dfs(int v,int fa){
	ok = ok & (curr_color == color[v]);
	for (auto u : itv[v]){
		if (u == fa)	continue;
		dfs(u,v);
	}
}

bool solve(int root){
	bool res = true;
	for (auto u : itv[root]){
		curr_color = color[u];
		ok = true;
		dfs(u,root);
		res = res & ok;
	}
	return res;
}

int main(){
	int n,u,v,root1 = -1,root2 = -1;
	scanf("%d",&n);
	for (int i = 1;i < n;i++){
		scanf("%d%d",&u,&v);
		itv[u].push_back(v);
		itv[v].push_back(u);
	}
	for (int i = 1;i <= n;i++)	scanf("%d",&color[i]);
	for (int i = 0;i < n;i++){
		for (auto u: itv[i]){
			if (color[u] != color[i]){
				root1 = u;
				root2 = i;
			}
		}
	}
	if (root1 == -1){
		printf("YES\n1");
	}
	else	if (solve(root1))	printf("YES\n%d\n",root1);
	else	if (solve(root2))	printf("YES\n%d\n",root2);
	else	printf("NO\n");
	return 0;
}

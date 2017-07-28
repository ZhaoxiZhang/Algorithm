#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100005;
int step[maxn],que[maxn],vis[maxn];

int bfs(int st,int ed)
{
	int E = 0,F = 0;
	que[F++] = st;
	vis[st] = 1;
	for (;;)
	{
		int now = que[E];
		if (now == ed)	return step[now];
		if (now + 1 < maxn && !vis[now + 1])	step[now + 1] = step[now] + 1,vis[now + 1] = 1,que[F++] = now + 1;
		if (now - 1 >= 0 &&!vis[now - 1])	step[now - 1] = step[now] + 1,vis[now - 1] = 1,que[F++] = now - 1;
		if (2*now < maxn && !vis[2*now])	step[2*now] = step[now] + 1,vis[2*now] = 1,que[F++] = 2 * now; 
		E++;
	}
}



int main()
{
	int N,K;
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&N,&K);
	if (N >= K)	printf("%d\n", N - K);
	else	printf("%d\n",bfs(N,K));
	return 0;
}

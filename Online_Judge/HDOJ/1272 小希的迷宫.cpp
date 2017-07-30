#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int vis[maxn];

int main()
{
	//freopen("input.txt","r",stdin);
	int x,y,num = 0,len = 0,flag = 0;
	memset(vis,0,sizeof(vis));
	while (~scanf("%d%d",&x,&y) && x != -1 && y != -1)
	{
		if (!x && !y)
		{
			if (!flag)	printf("Yes\n");
			else
			{
				if (num == len - 1)	printf("Yes\n");
				else	printf("No\n");
			}
			num = len = flag = 0;
			memset(vis,0,sizeof(vis));
			continue;
		}
		flag = 1;
		if (!vis[x])	len++;
		if (!vis[y])	len++;
		vis[x] = vis[y] = 1;
		num++;
	}
	return 0;
}

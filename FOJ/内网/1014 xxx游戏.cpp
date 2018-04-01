#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef __int64 LL;
vector<int>itv[5],edge[250];
int Indegree[250];
int In[250];
int id[250];
int solve(int x)
{
	int res = 0;
	queue<int>que[5];
	for (int i = 0;i < 250;i++)
	{
		In[i] = Indegree[i]; 
	}
	for (int i = 1;i <= 3;i++)
	{
		for (int j = 0;j < itv[i].size();j++)
		{
			if (In[itv[i][j]] == 0)
			{
				que[i].push(itv[i][j]);
			}
		}
	}
	for (int i = x;;i++)
	{
		i %= 3;
		if (i == 0) i = 3;
		while (!que[i].empty())
		{
			int val = que[i].front();
			que[i].pop();
			res++;
			for (int j = 0;j < edge[val].size();j++)
			{
				if (--In[edge[val][j]] == 0)
				{
					que[id[edge[val][j]]].push(edge[val][j]);
				}
			}
		}
		if (que[1].empty() && que[2].empty() && que[3].empty())
		{
			break;
		}
		res++;
	}
	return res;
}



int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		memset(Indegree,0,sizeof(Indegree));
		memset(id,0,sizeof(id));
		for (int i = 0;i < 5;i++)
		{
			itv[i].clear();
		}
		for (int i = 0;i < 250;i++)
		{
			edge[i].clear();
		}
		int N,cnt,tmp;
		scanf("%d",&N);
		for (int i = 1;i <= N;i++)
		{
			scanf("%d",&tmp);
			itv[tmp].push_back(i);
			id[i] = tmp;
		}
		for (int i = 1;i <= N;i++)
		{
			scanf("%d",&cnt);
			while (cnt--)
			{
				scanf("%d",&tmp);
				edge[tmp].push_back(i);
				Indegree[i]++;
			}
		}
		int res = 0x3f3f3f3f;
		for (int i = 1;i <= 3;i++)
		{
			res = min(res,solve(i));
		}
		printf("%d\n",res);
	}
	return 0;
} 

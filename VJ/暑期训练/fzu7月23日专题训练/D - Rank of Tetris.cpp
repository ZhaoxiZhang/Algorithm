#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 10005;
vector<int>edge[MAX];
int A[MAX],B[MAX],Indegree[MAX],root[MAX];
char str[MAX];
int N,M,sum;

void init()
{
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	memset(Indegree,0,sizeof(Indegree));
	memset(root,0,sizeof(root));
	for (int i = 0;i < N;i++)
	{
		root[i] = i;
		edge[i].clear();
	} 
}

int find(int x)
{
	if (root[x] == x)
		return x;
	else
	{
		return root[x] = find(root[x]);
	}
}

int unite(int x,int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return 0;
	root[y] = x;
	return 1;
}

void Topsort()
{
	bool uncertain = false;
	queue<int>que;
	for(int i = 0;i < N;i++)
	{
		if (Indegree[i] == 0 && find(i) == i)  //find(i) = i;避免同一个点被多次使用 
		{
			que.push(i);
		}
	}
	while (!que.empty())
	{
		if (que.size() > 1) uncertain = true;
		int val = que.front();
		que.pop();
		sum--;
		for (int i = 0;i < edge[val].size();i++)
		{
			if (--Indegree[edge[val][i]] == 0)
			{
				que.push(edge[val][i]);
			}
		}
	}
	if (sum > 0)  //存在环 
	{
		printf("CONFLICT\n");
	}
	else if (uncertain)
	{
		printf("UNCERTAIN\n");
	}
	else
	{
		printf("OK\n");
	}
}


int main()
{
	while (~scanf("%d%d",&N,&M))
	{
		int x,y;
		sum = N;
		init();
		for (int i = 0;i < M;i++)
		{
			scanf("%d %c %d",&A[i],&str[i],&B[i]);
			if (str[i] == '=')
			{
				if (unite(A[i],B[i]))
					sum--;
			}
		}
		for (int i = 0;i < M;i++)
		{
			if (str[i] == '=')	continue;
			x = find(A[i]);
			y = find(B[i]);
			if (str[i] == '>')
			{
				edge[x].push_back(y);
				Indegree[y]++;
			}
			else if (str[i] == '<')
			{
				edge[y].push_back(x);
				Indegree[x]++;
			}
		}
		Topsort();
	}
	return 0;
}


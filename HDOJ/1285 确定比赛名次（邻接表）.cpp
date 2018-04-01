#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int N,M;
	while (~scanf("%d%d",&N,&M))
	{
		int head[505],next[505],Indegree[505];
		int p1,p2;
		vector<int>Vex;
		priority_queue<int,vector<int>,greater<int> >que;
		memset(head,-1,sizeof(head));
		memset(next,0,sizeof(next));
		memset(Indegree,0,sizeof(Indegree));
		for (int i = 0;i < M;i++)
		{
			scanf("%d%d",&p1,&p2);
			next[i] = head[p1];
			head[p1] = i;
			Indegree[p2]++;
		}
		
		for (int i = 1;i <= N;i++)
		{
			if (Indegree[i] == 0)
			{
				que.push(i);
			}
		}
		
		while (!que.empty())
		{
			int val = que.top();
			que.pop();
			Vex.push_back(val);
			for (int i = head[val];i != -1;i = next[i])
			{
				if (--Indegree[i] == 0)
				{
					que.push(i);
				}
			}
		}
		bool first = true;
		for (int i = 0;i < Vex.size();i++)
		{
			first?printf("%d",Vex[i]):printf(" %d",Vex[i]);
			first = false; 
		}
		printf("\n");
	}
	return 0;
} 

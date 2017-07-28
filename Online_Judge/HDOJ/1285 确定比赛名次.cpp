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
		int Indegree[505] = {0};
		vector<int>Map[505],Vex;
		priority_queue<int,vector<int>,greater<int> >que;
		int p1,p2;
		while (M--)
		{
			scanf("%d%d",&p1,&p2);
			Map[p1].push_back(p2);
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
			for (int i = 0;i < Map[val].size();i++)
			{
				if (--Indegree[Map[val][i]] == 0)
				{
					que.push(Map[val][i]);
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

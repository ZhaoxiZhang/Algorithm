#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 30005;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n,m,p1,p2,Indegree[maxn] = {0};
		vector<int>edge[maxn],vex;
		priority_queue<int>que;
		scanf("%d%d",&n,&m);
		while (m--)
		{
			scanf("%d%d",&p1,&p2);
			edge[p2].push_back(p1);
			Indegree[p1]++; 
		}
		for (int i = 1;i <= n;i++)	if (Indegree[i] == 0)	que.push(i);
		while (!que.empty())
		{
			int val = que.top();
			que.pop();
			vex.push_back(val);
			for (int i = 0;i < edge[val].size();i++)
			{
				if (--Indegree[edge[val][i]] == 0)	que.push(edge[val][i]);
			}
		}
		int len = vex.size(); 
		printf("%d",vex[len-1]);
		for (int i = len-2;i >= 0;i--)	printf(" %d",vex[i]);
		printf("\n");
	}
	return 0;
}
/*input:
1
3 1
3 1
answer:
3 1 2
¶ø²»ÊÇ
2 3 1
*/ 

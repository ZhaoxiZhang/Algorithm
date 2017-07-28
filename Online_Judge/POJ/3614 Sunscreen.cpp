#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;

struct Node{
	int first,second;
};

bool cmp(Node x,Node y)
{
	return x.first < y.first;
}

int main()
{
	int C,L;
	while (~scanf("%d%d",&C,&L))
	{
		Node cow[2505],lot[2505];
		priority_queue<int,vector<int>,greater<int> >que;
		for (int i = 0;i < C;i++)
		{
			scanf("%d%d",&cow[i].first,&cow[i].second);
		}
		for (int i = 0;i < L;i++)
		{
			scanf("%d%d",&lot[i].first,&lot[i].second);
		}
		sort(cow,cow+C,cmp);
		sort(lot,lot+L,cmp);
		int sum = 0,j = 0;
		for (int i = 0;i < L;i++)
		{
			while (j < C && cow[j].first <= lot[i].first)
			{
				que.push(cow[j++].second);
			}
			while (!que.empty() && lot[i].second)
			{
				int tmp = que.top();
				que.pop();
				if (tmp < lot[i].first)
				{
					continue;
				}
				sum++;
				lot[i].second--;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
} 

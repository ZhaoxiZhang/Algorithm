#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	int N;
	while (~scanf("%d",&N) && N)
	{
		int tmp;
		priority_queue<int,vector<int>,greater<int> >que;
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&tmp);
			que.push(tmp);
		}
		int res = 0;
		while (que.size()>1)
		{
			int L1,L2;
			L1 = que.top();
			que.pop();
			L2 = que.top();
			que.pop();
			que.push(L1 + L2);
			res += L1 + L2;
		}
		printf("%d\n",res);
	}
	return 0;
}
 

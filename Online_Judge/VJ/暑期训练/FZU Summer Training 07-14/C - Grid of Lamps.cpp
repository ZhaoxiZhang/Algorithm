#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int M,N,tmp,sum = 0;
		vector<int>itv;
		priority_queue<int>que;
		queue<int>q;
		scanf("%d%d",&M,&N);
		while (M--)
		{
			scanf("%d",&tmp);
			que.push(tmp);
			sum += tmp;
		}
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&tmp);
			itv.push_back(tmp);
			sum += tmp;
		}
		for (int i = 0;i < N;i++)
		{
			while (!que.empty())
			{
				if (!itv[i])
				{
					break;
				}
				int tmp = que.top();
				que.pop();
				if (tmp > 0)
				{
					sum--;
					itv[i]--;
					tmp--;
				}
				q.push(tmp);
			}
			while (!q.empty())
			{
				tmp = q.front();
				que.push(tmp);
				q.pop();
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}

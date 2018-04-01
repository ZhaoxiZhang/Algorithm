#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;

int main()
{
	int N,x;
	priority_queue<int,vector<int>,greater<int> >que;
	scanf("%d",&N);
	for (int i = 0;i < N;i++)
	{
		scanf("%d",&x);
		que.push(x);
	}
	LL ans = 0;
	while (que.size()>1)
	{
		int q1,q2;
		q1 = que.top();que.pop();
		q2 = que.top();que.pop();
		ans += q1 + q2;
		que.push(q1+q2);
	}
	printf("%lld\n",ans);
	return 0;
}

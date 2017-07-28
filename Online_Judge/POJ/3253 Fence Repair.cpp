#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		priority_queue<int,vector<int>,greater<int> >pque;
		__int64 tmp,sum = 0;
		for (int i = 0;i < N;i++)
		{
			scanf("%I64d",&tmp);
			pque.push(tmp);
		}
		while (pque.size()>1)
		{
			int L1,L2;
			L1 = pque.top();
			pque.pop();
			L2 = pque.top();
			pque.pop();
			pque.push(L1+L2);
			sum += L1+L2; 
		}
		while (!pque.empty())
		{
			pque.pop();
		}
		printf("%I64d\n",sum);
	}
	return 0;
}

/*不能用逐减最大的方法求解 
4
8 8 8 5
*/

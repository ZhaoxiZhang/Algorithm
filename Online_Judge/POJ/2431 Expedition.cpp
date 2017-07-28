#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct oil{
	int dis,fuel;
};
bool cmp(struct oil x,struct oil y)
{
	/*if (x.dis > y.dis)
		return y.dis;
	else if (x.dis <= y.dis)
		return x.dis;*/
	return x.dis <= y.dis;
}

int main()
{
	int N;
	
	while (scanf("%d",&N) != EOF)
	{
		struct oil stops[10005];
		priority_queue<int>pque;
		int L,P;
		
		for (int i = 0;i < N;i++)
		{
			scanf("%d%d",&stops[i].dis,&stops[i].fuel);
		}
		
		scanf("%d%d",&L,&P);
		
		for (int i = 0;i < N;i++)
		{
			stops[i].dis = L - stops[i].dis;
		}
		
		sort(stops,stops + N,cmp);
		
		int cnt = 0;
		bool flag = true;
		for (int i = 0;i < N;i++)
		{
			if (P >= L)
			{
				break;
			}
			
			if (P < stops[i].dis)
			{
				if (pque.empty())
				{
					flag = false;
					break;
				}
				else
				{
					while (!pque.empty() && P < stops[i].dis)
					{
						cnt++;
						int tmp = pque.top();
						pque.pop();
						P += tmp;
					}
					if (pque.empty() &&  P < stops[i].dis)
					{
						flag = false;
						break;
					}
					pque.push(stops[i].fuel);
				}
			}
			else
			{
				pque.push(stops[i].fuel);
			}
		}
		
		if (P < L && !pque.empty())
		{
			int tmp = pque.top();
			pque.pop();
			P += tmp;
			cnt++;
		}
		
		if (!flag)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",cnt);
		}
	}
	return 0;
}

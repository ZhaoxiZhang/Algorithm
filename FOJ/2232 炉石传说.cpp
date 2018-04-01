#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;

struct Node{
	int first,second;
};

bool cmp1(Node x,Node y)
{
	return x.first > y.first;
}

bool cmp2(Node x,Node y)
{
	return x.second > y.second;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N,kill = 0;
		bool flag = true;
		Node our[100005],you[100005];
		memset(our,0,sizeof(our));
		memset(you,0,sizeof(you));
		multiset<int>s;
		multiset<int>::iterator it;
		scanf("%d",&N);
		for (int i = 0;i < N;i++)
		{
			scanf("%d%d",&our[i].second,&our[i].first);
		}
		for (int i = 0;i < N;i++)
		{
			scanf("%d%d",&you[i].second,&you[i].first);
		}
		sort(our,our+N,cmp1);
		sort(you,you+N,cmp2);
		int j = 0;
		for (int i = 0;i < N;i++)
		{
			while (j < N && our[j].first >= you[i].second)
			{
				s.insert(our[j++].second);
			}
			if (s.empty())
			{
				flag = false;
				break;
			}
			it = s.upper_bound(you[i].first);
			if (it == s.end())
			{
				it = s.begin();
			}
			if (*it <= you[i].first)
			{
				kill++;
			}
			s.erase(it);
		}
		if(!flag)
		{
			printf("No\n");
		}
		else
		{
			if (kill != 0)
			{
				printf("No\n");
			}
			else
			{
				printf("Yes\n"); 
			}
		}
		//printf("Case #%d: %d\n",Case++,flag?(N-kill):-1);
	}
	return 0;
}

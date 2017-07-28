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
	int T,Case = 1;
	scanf("%d",&T);
	while (T--)
	{
		int N,M,kill = 0;
		bool flag = true;
		Node our[100005],you[100005];
		memset(our,0,sizeof(our));
		memset(you,0,sizeof(you));
		multiset<int>s;
		multiset<int>::iterator it;
		scanf("%d%d",&N,&M);
		for (int i = 0;i < N;i++)
		{
			scanf("%d%d",&our[i].first,&our[i].second);
		}
		for (int i = 0;i < M;i++)
		{
			scanf("%d%d",&you[i].first,&you[i].second);
		}
		sort(our,our+N,cmp1);
		sort(you,you+M,cmp2);
		int j = 0;
		for (int i = 0;i < M;i++)
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
		printf("Case #%d: %d\n",Case++,flag?(N-kill):-1);
	}
	return 0;
}

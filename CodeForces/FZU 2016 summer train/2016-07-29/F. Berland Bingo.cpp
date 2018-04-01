#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

bool OK(vector<int>a,vector<int>b)//a in b?
{
	int lena = a.size();
	int lenb = b.size();
	for (int i = 0;i < lena;i++)
	{
		bool in = false;
		for (int j = 0;j < lenb;j++)
		{
			if (a[i] == b[j])
			{
				in = true;
			}
		} 
		if (!in)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		vector<int>itv[105];
		int ans[105] = {0};
		int M,tmp;
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&M);
			while (M--)
			{
				scanf("%d",&tmp);
				itv[i].push_back(tmp);
			} 
		}
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < N;j++)
			{
				if (j == i)	continue;
				if (OK(itv[i],itv[j]))
				{
					ans[j] = 1;
				}
			}
		}
		for (int i = 0;i < N;i++)
		{
			if (!ans[i])
			{
				printf("YES\n");
			} 
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;
} 

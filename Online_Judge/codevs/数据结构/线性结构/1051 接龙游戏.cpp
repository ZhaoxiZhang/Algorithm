#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<string> 
#include<algorithm>
using namespace std;
const int maxn = 100005;
string word[maxn];

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		stack<int>stk;
		int res = 1;
		for (int i = 0;i < N;i++)
		{
			cin >> word[i];
		}
		sort(word,word+N);
		stk.push(0);
		for (int i = 1;i < N;i++)
		{
			bool flag = false;
			while (!stk.empty())
			{
				int tmp = stk.top();
				int len1 = word[tmp].size();
				int len2 = word[i].size();
				if (len2 > len1)
				{
					flag = true;
					for (int j = 0;j < len1;j++)
					{
						if (word[tmp][j] != word[i][j])
						{
							flag = false;
							break;
						}
					}
				}
				if (flag)	break;
				stk.pop();
			}
			stk.push(i);
			int len3 = stk.size();
			res = max(res,len3);
		}
		printf("%d\n",res);
	}
	return 0;
} 

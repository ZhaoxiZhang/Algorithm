#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;

int main()
{
	LL N;
	while (cin >> N)
	{
		LL res = 0,cnt = 1;
		LL ans[100005] = {0};
		bool flag = false;
		for (int i = 0;i < N;i++)
		{
			scanf("%I64d",&ans[i]);
		}
		int i = 0;
		while (i < N - 1)
		{
			while (ans[i] == ans[i+1])
			{
				cnt++;
				if (i == N - 2)
				{
					flag = true;
				}
				i++;
			}
			res += ((1+cnt)*cnt/2);
			cnt = 1;
			i++;
		}
		if(!flag)
		{
			res += 1;
		}
		cout << res << endl;
	}
	return 0;
}

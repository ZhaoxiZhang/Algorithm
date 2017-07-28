#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	string home,away,opt,letter;
	int ans[2][105] = {0};
	bool flag[2][105];
	memset(flag,false,sizeof(flag));
	int N,t,num;
	cin >> home >> away;
	scanf("%d",&N);
	for (int i = 0;i < N;i++)
	{
		scanf("%d",&t);
		cin >> opt;
		if (opt == "h")
		{
			scanf("%d",&num);
			cin >> letter;
			if (letter == "r")
			{
				if (!flag[0][num])
				{
					cout <<home << " " << num << " " << t << endl;
					flag[0][num] = true;
				}
			}
			else if (letter == "y")
			{
				ans[0][num]++;
				if (ans[0][num] % 2 == 0)
				{
					if (!flag[0][num])
					{
						cout <<home << " " << num << " " << t << endl;
						flag[0][num] = true;
					}
				}
			}
		}
		else if (opt == "a")
		{
			scanf("%d",&num);
			cin >> letter;
			if (letter == "r")
			{
				if (!flag[1][num])
				{
					cout << away << " " << num << " " << t << endl;
					flag[1][num] = true;
				}
			}
			else if (letter == "y")
			{
				ans[1][num]++;
				if (ans[1][num] % 2 == 0)
				{
					if (!flag[1][num])
					{
						cout << away << " " << num << " " << t << endl;
						flag[1][num] = true;
					}
				}
			}
		}
	}
	return 0;
}

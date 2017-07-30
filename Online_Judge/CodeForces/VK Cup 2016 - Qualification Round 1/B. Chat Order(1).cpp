#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
string str[maxn];
map<string,int>mp;

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		cin >> str[i];
	}
	for (int i = n - 1;i >= 0;i--)
	{
		if (!mp[str[i]]++)
		{
			cout << str[i] << endl;
		}
	}
	return 0;
} 

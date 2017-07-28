#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a, string b)
{
	return a+b < b+a;
}


int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N;
		scanf("%d",&N);
		string str[10005];
		for (int i = 0;i < N;i++)
		{
			cin >> str[i];
		}
		sort(str,str+N,cmp);
		for (int i = 0 ;i < N;i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
	return 0;
} 

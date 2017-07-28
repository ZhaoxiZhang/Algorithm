#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

bool cmp(string a,string b)
{
	return a+b > b+a;
}


int main()
{
	int N;
	while (~scanf("%d",&N) && N)
	{
		string str[55];
		for (int i = 0;i < N;i++)
		{
			cin >> str[i];
		}
		sort(str,str + N,cmp);
		for (int i = 0;i < N;i++)
		{
			cout << str[i];
		}
		printf("\n");
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn],Left[maxn],Right[maxn];

int main()
{
	int n,res = 0;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		Left[i] = Left[i-1]+a[i];
	}
	for (int i = n;i > 0;i--)
	{
		Right[i] = Right[i+1] + a[i];
	}
	//for (int i = 1;i <= n;i++)	cout << Left[i] << " ";
	//cout << endl;
	for (int i = 1;i < n;i++)
	{
		if (Left[i] == Right[i+1])	res++;
	}
	printf("%d\n",res);
	return 0;
} 

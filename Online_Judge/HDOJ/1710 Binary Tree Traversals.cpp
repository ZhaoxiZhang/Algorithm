#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;

void post(int n,int a[],int b[],int c[])
{
	if (n <= 0)	return;
	int pos;
	for (int i = 0;i < n;i++)
		if (b[i] == a[0])	pos = i;
	post(pos,a + 1,b,c);
	post(n - pos - 1,a + pos + 1,b + pos + 1,c + pos);
	c[n - 1] = a[0];
}

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int a[maxn],b[maxn],c[maxn];
		for (int i = 0;i < N;i++)	scanf("%d",&a[i]);
		for (int i = 0;i < N;i++)	scanf("%d",&b[i]);
		post(N,a,b,c); 
		printf("%d",c[0]);
		for (int i = 1;i < N;i++)	printf(" %d",c[i]);
		printf("\n");
	}
	return 0;
} 

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		__int64 n;
		scanf("%I64d",&n);
		printf("%I64d\n",2*n*n-n+1);
	}
	return 0;
}

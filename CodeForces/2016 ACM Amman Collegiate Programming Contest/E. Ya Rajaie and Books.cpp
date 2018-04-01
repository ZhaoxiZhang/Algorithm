#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N;
		scanf("%d",&N);
		printf("%d\n",N % 5 == 0?N/5:N/5+1);
	}
	return 0;
} 

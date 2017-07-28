#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 4005;
int cd[maxn*maxn];

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int a[maxn],b[maxn],c[maxn],d[maxn];
		for (int i = 0;i < N;i++)	scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		for (int i = 0;i < N;i++)	for (int j = 0;j < N;j++)	cd[i*N+j] = c[i] + d[j];
		sort(cd,cd + N*N);
		int res = 0;
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < N;j++)
			{
				int tmp = -a[i] - b[j];
				int pos1 = lower_bound(cd,cd + N*N,tmp) - cd;
				int pos2 = upper_bound(cd,cd + N*N,tmp) - cd;
				res += pos2 - pos1; 
			}
		}
		printf("%d\n",res);
	}
	return 0;
}

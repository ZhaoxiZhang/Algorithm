#include<bits/stdc++.h>
using namespace std;
const int maxn = 25;

bool solve(int a[][maxn],int N,int M,int c1,int c2)
{
	int atmp[maxn][maxn];
	for (int i = 0;i < N;i++)	for (int j = 0;j < M;j++)	atmp[i][j] = a[i][j]; 
	for (int i = 0;i < N;i++)	swap(atmp[i][c1],atmp[i][c2]);
	for (int i = 0;i < N;i++)
	{
		int cnt = 0;
		for (int j = 0;j < M;j++)
		{
			if (atmp[i][j] != j + 1)	cnt++;
		}
		if (cnt > 2)	return false;
	}
	return true;
} 

int main()
{
	int N,M,a[maxn][maxn];
	while (~scanf("%d%d",&N,&M))
	{
		for (int i = 0;i < N;i++)	for (int j = 0;j < M;j++)	scanf("%d",&a[i][j]);
		bool flag = false;
		for (int i = 0;i < M - 1;i++)
		{
			for (int j = i + 1;j < M;j++)
			{
				flag = solve(a,N,M,i,j);
				if (flag)	break;
			}
			if (flag)	break;
		} 
		if (flag)	printf("YES\n");
		else
		{
			int cnt = 0;
			for (int i = 0;i < N;i++)
			{
				cnt = 0;
				for (int j = 0;j < M;j++)
				{
					if (a[i][j] != j + 1)	cnt++;
					if (cnt > 2)	break;
				}
				if (cnt > 2)	break;
			}
			if (cnt > 2)	printf("NO\n");
			else	printf("YES\n");
		}
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int abx(int x)
{
	if (x < 0)
		return -x;
	else
		return x;
}

int main()
{
	int N,M;
	while (~scanf("%d%d",&N,&M))
	{
		int res = 0,maxx = 0,tmp = 0;
		int left[155],right[155];
		char maze[155][155];
		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));
		for (int i = 0;i < N;i++)
		{
			left[i] = INF;
			right[i] = -INF;
			scanf("%s",maze[i]);
			for (int j = 0;j < M;j++)
			{
				if (maze[i][j] == 'W')
				{
					left[i] = min(left[i],j);
					right[i] = max(right[i],j);
				}
			}
		} 
		for (int i = 0;i < N;i++)
		{
			if (left[i] <= right[i])
			{
				maxx = i;
				if (!(i&1))
				{
					res += abx(tmp - left[i]) + right[i] -  left[i];
					tmp = right[i];
				}
				else
				{
					res += abx(tmp - right[i]) + right[i] - left[i];
					tmp = left[i];
				}
			}
		}
		printf("%d\n",res + maxx);
	}
	return 0;
} 

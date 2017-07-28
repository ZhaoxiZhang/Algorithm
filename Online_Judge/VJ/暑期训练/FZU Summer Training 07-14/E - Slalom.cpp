#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct Node{
	int x,y;
};

Node pos[100005];
int s[1000005];
int W,vh,N,S;

bool OK(int val)
{
	double left = pos[0].x,right = pos[0].x + W;
	for (int i = 0;i < N - 1;i++)
	{
		double dis = pos[i+1].y - pos[i].y;
		double t = dis/val;
		left -= t*vh;
		right += t*vh;
		if (left > pos[i+1].x + W|| right < pos[i+1].x)
		{
			return false;
		}
		if (left < pos[i+1].x)
		{
			left = pos[i+1].x; 
		}
		if (right < pos[i+1].x + W)
		{
			right = pos[i+1].x + W;
		}
	}
	return true;
}



int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int res = 0;
		memset(pos,0,sizeof(pos));
		memset(s,0,sizeof(s));
		scanf("%d%d%d",&W,&vh,&N);
		for (int i = 0;i < N;i++)
		{
			scanf("%d%d",&pos[i].x,&pos[i].y);
		}
		scanf("%d",&S);
		for (int i = 0;i < S;i++)
		{
			scanf("%d",&s[i]);
		}
		sort(s,s+S);
		if (!OK(s[0]))
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		int lb = 0,ub = S;
		while (lb < ub)
		{
			int mid = (lb + ub)/2;
			if (OK(s[mid]))
			{
				res = s[mid];
				lb = mid + 1;
			}
			else
			{
				ub = mid;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}

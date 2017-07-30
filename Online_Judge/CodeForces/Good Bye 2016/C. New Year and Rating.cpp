#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int Left = -20000000;
const int Right = 20001900;
struct Node{
	int val,type;
}node[maxn];
int n;

bool OK(int x)
{
	for (int i = 0;i < n;i++)
	{
		if (node[i].type == 1)
		{
			if (x < 1900)	return true;
			x += node[i].val;
		}
		else
		{
			if (x > 1899)	return false;
			x += node[i].val;
		}
	}
	return true;
}

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for (int i = 0;i < n;i++)	scanf("%d%d",&node[i].val,&node[i].type);
	int left = Left,right = Right + 300;
	while (left < right - 1)
	{
		int mid = left + ((right-left)>>1);
		if (OK(mid))
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	int val = left,sum = left;
	for (int i = 0;i < n;i++)
	{
		if (node[i].type == 1)
		{
			if (sum < 1900)
			{
				printf("Impossible\n");
				return 0;
			}
			else	sum += node[i].val;
		}
		else
		{
			if (sum > 1899)
			{
				printf("Impossible\n");
				return 0;
			}
			else	sum += node[i].val;
		}
	}
	if (val >= Right)	printf("Infinity\n");
	else	printf("%d\n",sum);
	return 0;
}

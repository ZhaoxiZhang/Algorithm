#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod = 999991;
const int maxn = 100005;
int tot = 0,head[mod+5],num[maxn][6],next[maxn];

int IndexHash(int id)
{
	int hashval = 0;
	for (int i = 0;i < 6;i++)	hashval = (hashval%mod+num[id][i]%mod)%mod;
	return hashval%mod;
}

bool cmp(int id1,int id2)
{
	bool flag;
	for (int i = 0;i < 6;i++)
	{
		flag = true;
		for (int st = i,j = 0; j < 6;j++,st = (st+1) == 6?0:st+1)
		{
			if (num[id1][st] != num[id2][j])
			{
				flag = false;
				break;
			}
		}	
		if (flag)	return true;
	}
	
	for (int i = 0;i < 6;i++) 
	{
		flag = true;
		for (int st = i,j = 5;j >= 0;j--,st = (st+1)==6?0:(st+1))
		{
			if (num[id1][st] != num[id2][j])
			{
				flag = false;
				break;
			}
		} 
		if (flag)	return true;
	}
	return false;
}

void addnode(int hashval)
{
	next[tot] = head[hashval];
	head[hashval] = tot++;
}

bool solve(int id)
{
	int hashval = IndexHash(id);
	for (int i = head[hashval]; i != -1;i = next[i])
	{
		if (cmp(i,id))	return true;
	}
	addnode(hashval);
	return false;
}

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		memset(head,-1,sizeof(head));
		bool flag = false;
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < 6;j++)	scanf("%d",&num[i][j]);
			if (flag)	continue;
			flag = solve(i); 	
		}
		if (flag)	printf("Twin snowflakes found.\n");
		else	printf("No two snowflakes are alike.\n");
	} 
	return 0;
}

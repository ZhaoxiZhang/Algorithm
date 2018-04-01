#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
struct Node{
	int cnt;
	int next[26];
	Node()
	{
		cnt = 0;
		memset(next,-1,sizeof (next));
	}
}node[maxn];
int tot = 1;
char str[30];

void insert(char *s)
{
	int i = 0,p = 0;
	while (s[i])
	{
		int x = s[i] - 'a';
		if (node[p].next[x] == -1)
		{
			node[p].next[x] = tot++;
		}
		p = node[p].next[x];
		node[p].cnt++;
		i++;
	}
}

void qry(char *s)
{
	int i = 0,p = 0;
	while (s[i])
	{
		int x = s[i] - 'a';
		if (node[p].next[x] == -1)
		{
			puts("0");
			return;
		}
		p = node[p].next[x];
		i++;
	}
	printf("%d\n",node[p].cnt);
}

int main()
{
	freopen("input.txt","r",stdin);
	int n,m;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%s",str);
		insert(str);
	}
	scanf("%d",&m);
	while (m--)
	{
		scanf("%s",str);
		qry(str); 
	}
	return 0;
} 

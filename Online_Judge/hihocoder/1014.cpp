#include<bits/stdc++.h>
using namespace std;
struct trie{
	int cnt;
	struct trie *next[26];
	trie()
	{
		cnt = 0;
		memset(next,0,sizeof(next));
	} 
}; 
char str[30];
 
int main()
{
	//freopen("input.txt","r",stdin);
	trie *root = new trie;
	int n,m;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%s",str);
		trie *p = root;
		int i = 0;
		while (str[i])
		{
			int x = str[i] - 'a';
			if (p->next[x])
			{
				p->next[x]->cnt++;
			}
			else
			{
				trie *q = new trie;
				q->cnt = 1;
				p->next[x] = q;
			}
			p = p->next[x];
			i++;
		}
	}
	scanf("%d",&m);
	while (m--)
	{
		scanf("%s",str);
		bool flag = false;
		trie *p = root;
		int i = 0;
		while (str[i])
		{
			int x = str[i] - 'a';
			if (!p->next[x])
			{
				flag = true;
				break;
			}
			p = p->next[x];
			i++;
		}
		if (flag)	puts("0");
		else	printf("%d\n",p->cnt);
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 500*205;
int nxt[60060][128],fail[maxn],id[maxn];
char str[10005];
queue<int>que;
int root,tot,res;

void init()
{
    memset(nxt,0,sizeof(nxt));
    memset(fail,0,sizeof(fail));
    memset(id,0,sizeof(id));
    root = 0;
    tot = 0;
    res = 0;
    while (!que.empty())	que.pop();
}

void insert(char* s,int index)
{
    int p = root;
    int len = strlen(s);
    for (int i = 0;i < len;i++)
    {
    	int x = s[i];
        if (!nxt[p][x]) nxt[p][x] = ++tot;
        p = nxt[p][x];
    }
    id[p] = index;
}


void build()
{
    que.push(root);
    while (!que.empty())
    {
        int p = que.front();
        que.pop();
        for (int i = 0;i < 128;i++)
        {
            if (nxt[p][i])
            {
                if (p == root)  fail[nxt[p][i]] = root;
                else    fail[nxt[p][i]] = nxt[fail[p]][i];
                que.push(nxt[p][i]);
            }
            else
            {
                if (p == root)  nxt[p][i] = root;
                else    nxt[p][i] = nxt[fail[p]][i];
            }
        }
    }
}

void solve(char* s,int index)
{
    int p = root;
    vector<int>itv;
    int len = strlen(s);
    for (int i = 0;i < len;i++)
    {
    	int x = s[i];
        p = nxt[p][x];
        for (int tmp = p;tmp != root;tmp = fail[tmp])
        {
            if (id[tmp])    itv.push_back(id[tmp]);
        }
    }
    len = itv.size();
    if (len)
    {
        res++;
        sort(itv.begin(),itv.end());
        printf("web %d:",index);
        for (int i = 0;i < len;i++) printf(" %d",itv[i]);
        printf("\n");
    }
}

int main()
{
	//freopen("input.txt","r",stdin);
    int N;
    while (~scanf("%d",&N))
    {
        init();
        for (int i = 1;i <= N;i++)
        {
        	scanf("%s",str);
            insert(str,i);
        }
        build();
        int M;
        scanf("%d",&M);
        for (int i = 1;i <= M;i++)
        {
            scanf("%s",str);
            solve(str,i);
        }
        printf("total: %d\n",res);
    }
    return 0;
}

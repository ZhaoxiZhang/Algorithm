#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;

struct Trie{
    bool flag;
    struct Trie* nxt[26];
    struct Trie* behind;
};

int main()
{
	//freopen("input.txt","r",stdin); 
    char str[maxn];
    int N;
    Trie* root = new Trie;
    for (int i = 0;i < 26;i++)
    {
        root->nxt[i] = NULL;
    }
    root->behind = NULL;
    root->flag = false;
    scanf("%d",&N);
    while (N--)
    {
        scanf("%s",str);
        Trie* p = root;
        int i = 0;
        while (str[i])
        {
            int j = str[i] - 'a';
            if (!p->nxt[j])
            {
                Trie* q = new Trie;
                for (int k = 0;k < 26;k++)  q->nxt[k] = NULL;
                q->behind = NULL;
                q->flag = false;
                p->nxt[j] = q;
            }
            p = p->nxt[j];
            i++;
        }
        p->flag = true;
    }
    queue<Trie*>que;
    root->behind = root;
    for (int i = 0;i < 26;i++)
    {
        if (!root->nxt[i])
        {
            root->nxt[i] = root;
        }
        else
        {
            root->nxt[i]->behind = root;
            que.push(root->nxt[i]);
        }
    }

    while (!que.empty())
    {
        Trie* p = que.front();
        Trie* q = p->behind;
        que.pop();
        for (int i = 0;i < 26;i++)
        {
            if (!p->nxt[i])
            {
                p->nxt[i] = q->nxt[i];
            }
            else
            {
                p->nxt[i]->behind = q->nxt[i];
                que.push(p->nxt[i]);
            }
        }
    }
    char article[maxn];
    Trie* p = root;
    scanf("%s",article);
    int i = 0;
    bool tag = false;
    while (article[i])
    {
        int j = article[i] - 'a';
        p = p->nxt[j];
        if (p->flag)
        {
            tag = true;
            printf("YES\n");
            break;
        }
        i++;
    }
    if (!tag)   printf("NO\n");
    return 0;
}

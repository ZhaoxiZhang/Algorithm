#include<bits/stdc++.h>
using namespace std;

struct Trie{
    int cnt;
    Trie* next[26];
    Trie* behind;
};


int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int N;
        char str[60];
        Trie* root = new Trie;
        root->cnt = -1;
        root->behind = NULL;
        for (int i = 0;i < 26;i++)  root->next[i] = NULL;
        scanf("%d",&N);
        while (N--)
        {
            scanf("%s",str);
            Trie* p = root;
            int i = 0;
            while (str[i])
            {
                int j = str[i] - 'a';
                if (!p->next[j])
                {
                    Trie* q = new Trie;
                    q->cnt = 0;
                    q->behind = NULL;
                    for (int k = 0;k < 26;k++)  q->next[k] = NULL;
                    p->next[j] = q;
                }
                p = p->next[j];
                i++;
            }
            p->cnt++;
        }
        queue<Trie*>que;
        root->behind = root;
        for (int i = 0;i < 26;i++)
        {
            if (!root->next[i])
            {
                root->next[i] = root;
            }
            else
            {
                root->next[i]->behind = root;
                que.push(root->next[i]);
            }
        }
        while (!que.empty())
        {
            Trie* p = que.front();
            Trie* q = p->behind;
            que.pop();
            for (int i = 0;i < 26;i++)
            {
                if (!p->next[i])
                {
                    p->next[i] = q->next[i];
                }
                else
                {
                    p->next[i]->behind = q->next[i];
                    que.push(p->next[i]);
                }
            }
        }
        char article[1000005];
        Trie* p = root;
        scanf("%s",article);
        int res = 0;
        int i = 0;
        while (article[i])
        {
            int j = article[i] - 'a';
            p = p->next[j];
            for (Trie* tmp = p;tmp != root && tmp->cnt !=-1;tmp = tmp->behind)
            {
            	res += tmp->cnt;
            	tmp->cnt = -1;
            }
            i++;
        }
        printf("%d\n",res);
    }
    return 0;
}

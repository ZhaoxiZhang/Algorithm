#include<bits/stdc++.h>
using namespace std;
const int N = 500005;

struct AC_Automan{
    int next[N][26];
    int fail[N];
    int cnt[N];
    int root,tot;
    int newnode()
    {
        for (int i = 0;i < 26;i++)  next[tot][i] = -1;
            fail[tot] = -1;
        cnt[tot] = 0;
        return tot++;
    }
    void clear()
    {
        tot = 0;
        root = newnode();
    }
    void insert(const string &s)
    {
        int p = root;
        for (int i = 0,len = s.length();i < len;i++)
        {
            if (next[p][s[i]-'a'] == -1)    next[p][s[i]-'a'] = newnode();
            p = next[p][s[i]-'a'];
        }
        cnt[p]++;
    }
    void build()
    {
        queue<int>Q;
        Q.push(root);
        while (!Q.empty())
        {
            int p = Q.front();Q.pop();
            for (int i = 0;i < 26;i++)
            {
                if (~next[p][i])
                {
                    if (p == root)  fail[next[p][i]] = root;
                    else    fail[next[p][i]] = next[fail[p]][i];
                    Q.push(next[p][i]);
                }
                else
                {
                    if (p == root)  next[p][i] = root;
                    else    next[p][i] = next[fail[p]][i];
                }
            }
        }
    }
    int solve(const string &t)
    {
        int p = root,ans = 0;
        for (int i = 0,len = t.length();i < len;i++)
        {
            p = next[p][t[i]-'a'];
            for (int tmp = p;tmp != root && cnt[tmp] != -1;tmp = fail[tmp])
            {
                ans += cnt[tmp];
                cnt[tmp] = -1;
            }
        }
        return ans;
    }
}ac;

int main()
{
    cin.sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        ac.clear();
        int n;
        cin >> n;
        for (int i = 0;i < n;i++)
        {
            string s;
            cin >> s;
            ac.insert(s);
        }
        ac.build();
        string t;
        cin >> t;
        cout << ac.solve(t) << endl;
    }
    return 0; 
}

#include<iostream>
#include<cstdio>
using namespace std;

int n, m, a, b, ths, f[1001], e[1001], v[1001];
char ch;

int find(int x)
{

    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    f[y] = x;
}

int main()
{

    cin >> n >> m;
    for(int i = 1; i <= n; i++) f[i] = i;
    for(int i = 1; i <= m; i++)
    {
        cin >> ch >> a >> b;
        if(ch == 'F') merge(a, b);
        if(ch == 'E')
        {
            if(e[b]) merge(a, e[b]);
            if(e[a]) merge(e[a], b);
            e[a] = b;
        }
    }

    for(int i = 1; i <= n; i++)

        if(!v[find(i)])
        {
            v[find(i)] = 1;
            ++ths;
        }
    cout << ths << endl;
    return 0;
}

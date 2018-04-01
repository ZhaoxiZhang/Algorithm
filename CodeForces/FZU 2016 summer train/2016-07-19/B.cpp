#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

const int N = 1e3+5;
char mp[N][N];
int nc[N], nr[N];
int n, m;
int sum = 0;

bool fun ()
{
    int tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp = nc[i] + nr[j];
            if (mp[i][j] == '*') tmp--;
            if (sum == tmp)
            {
                puts("YES");
                printf("%d %d\n", i+1, j+1);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", mp[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == '*')
            {
                nc[i]++;
                nr[j]++;
                sum++;
            }
        }
    }
    if (!fun()) puts("NO");
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int a[maxn], pos[maxn] = {0};

int main()
{
    int n, t, c, p = 1, res = 0;
    scanf("%d%d%d", &n, &t, &c);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > t)   pos[p++] = i;
    }
    pos[p++] = n + 1;
    if (pos[1] == 0)	res += 1 + (n - c);
    else
    {
        for (int i = 1; i < p; i++)
        {
            int len = pos[i] - pos[i - 1] - 1;
            if (len >= c)
            {
                res += 1 + (len - c);
            }
        }
    }
    printf("%d\n", res);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;
const int maxn = 100005;
int a[maxn];
map<int, bool>mp;

int main()
{
    int b, q, l, m;
    scanf("%d%d%d%d", &b, &q, &l, &m);
    for (int i = 0; i < m; i++)   scanf("%d", &a[i]), mp[a[i]] = true;
    if (q < 0)
    {
        if (q == -1 && mp[b] && mp[-b]) printf("0\n");
        else printf("inf\n");
    }
    else if (q == 0)
    {
        if ((mp[0] && mp[b]) || (mp[0] && b > l))  printf("0\n");
        else if (mp[0] && !mp[b] && b <= l)  printf("1\n");
        else printf("inf\n");
    }
    else
    {
        if ((q == 1 && mp[b]) || (q == 1 && b > l))    printf("0\n");
        else if (q == 1 && !mp[b] && b <= l)  printf("inf\n");
        else
        {
            LL tmp = b;
			int res = 0;
            while (tmp <= l)
            {
                if (!mp[tmp])   res++;
                tmp = tmp*(LL)q;
            }
            printf("%d\n", res);
        }
    }
    return 0;
}

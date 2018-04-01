#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];

bool OK(int m, int s)
{
    return s >= 0 && s <= m * 9;
}

int main()
{
    int m, s;
    scanf("%d%d", &m, &s);
    if (!OK(m, s) || (m > 1 && s == 0))  printf("-1 -1\n");
    else
    {
        int cnt = 0, sum = s;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (((i > 0 || j > 0) || (m == 1 && j == 0)) && OK(m - i - 1, sum - j))
                {
                    sum -= j;
                    a[cnt++] = j;
                    break;
                }
            }
        }

        for (int i = 0; i < cnt; i++) printf("%d", a[i]);
        printf(" ");
        cnt = 0, sum = s;
        for (int i = 0; i < m; i++)
        {
            for (int j = 9; j >= 0; j--)
            {
                if (((i > 0 || j > 0) || (m == 1 && j == 0)) && OK(m - i - 1, sum - j))
                {
                    sum -= j;
                    a[cnt++] = j;
                    break;
                }
            }
        }
        for (int i = 0; i < cnt; i++) printf("%d", a[i]);
        puts("\40");
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int INF = 1000005;

int main()
{
    int n, dif, minn = INF;
    scanf("%d", &n);
    int a = 1, b = n;
    int m = sqrt(n + 0.5);
    for (int i = 1; i <= m; i++)
    {
        if (!(n % i))
        {
            dif = n / i - i;
            if (dif < minn)
            {
                a = i, b = n / i;
                minn = dif;
            }
        }
    }
    printf("%d %d\n", a, b);
    return 0;
}

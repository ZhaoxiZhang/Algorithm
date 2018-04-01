#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int a[maxn];

int main()
{
    int N;
    while (~scanf("%d", &N))
    {
        for (int i = 0; i < N; i++) scanf("%d", &a[i]);
        sort(a, a + N);
        int cnt = 1, pos = 0;
        for (int i = 1; i < N; i++)
        {
            if (a[i] == a[i - 1]) cnt++;
            else  cnt = 1;
            if (cnt >= (N + 1) / 2)
            {
                pos = i;
                break;
            }
        }
        printf("%d\n", a[pos]);
    }
    return 0;
}

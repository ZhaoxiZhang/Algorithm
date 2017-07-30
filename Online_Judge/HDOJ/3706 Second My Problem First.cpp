#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;
const int maxn = 10005;
int a[maxn], q[maxn];
int main()
{
    //freopen("input.txt","r",stdin);
    int n, A, B;
    while(scanf("%d%d%d", &n, &A, &B) != EOF)
    {
        
		int head = 1, tail = 0;
        LL res = 1, S = 1;
        for (int i = 1; i <= n; i++)
        {
            S = S * A % B;
            a[i] = S;
            while (head <= tail && S <= a[q[tail]]) tail--;
            q[++tail] = i;
            while (head <= tail && q[head] < i - A) head++;
            res = (res * a[q[head]]) % B;
        }
        printf("%I64d\n",res);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn];

int main()
{
    int n,k,res = 0;
    scanf("%d%d",&n,&k);
    for (int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
        res += (a[i] + (k - 1))/k;
    }
    res = (res + 1)>>1; 
    printf("%d\n",res);
    return 0;
}

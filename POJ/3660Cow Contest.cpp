#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1005;
int a[maxn],b[maxn];

int main()
{
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    for (int i = 0;i < m;i++)
    {
        scanf("%d%d",&x,&y);
        a[y]++,b[x]++;
    }
    int res = 0;
    for (int i = 1;i <= n;i++)
    {
        if (a[i] + b[i] == n - 1)
        {
            res++; 
        }
    }
    printf("%d\n",res);
    return 0;
}

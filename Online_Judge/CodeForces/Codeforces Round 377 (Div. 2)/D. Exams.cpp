#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn],d[maxn],book[maxn];
int n,m;

bool OK(int x)
{
    int sum = 0,cnt = 0;
    memset(book,0,sizeof(book));
    for (int i = x;i > 0;i--)
    {
        if (d[i] && !book[d[i]])
        {
            book[d[i]] = 1;
            cnt++;
            sum += a[d[i]];
        }
        else if (sum > 0)   sum--;
    }
    if (cnt < m)    return false;
    else if (sum > 0)   return false;
    else    return true;
}


int main()
{
    bool flag = false;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++)   scanf("%d",&d[i]);
    for (int i = 1;i <= m;i++)   scanf("%d",&a[i]);
    int left = 0,right = maxn;
    while (left < right)
    {
        int mid = left + ((right - left)>>1);
        if (OK(mid))
        {
            right = mid;
            flag = true;
        }
        else
        {
            left = mid + 1;
        }
    }
    if (flag)   printf("%d\n",right);
    else    printf("-1\n");
    return 0;
}

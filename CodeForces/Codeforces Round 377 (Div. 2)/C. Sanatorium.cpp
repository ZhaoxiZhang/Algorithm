#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;

int main()
{
    LL b,d,s;
    scanf("%I64d%I64d%I64d",&b,&d,&s);
    LL maxx = max(max(b,d),s);
    LL maxb = max(maxx-1,b);
    LL maxd = max(maxx-1,d);
    LL maxs = max(maxx-1,s);
    cout << (maxb + maxd + maxs - (b + d + s)) << endl;
    return 0;
}

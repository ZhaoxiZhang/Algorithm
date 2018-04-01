#include<bits/stdc++.h>
typedef  __int64 ll; 
#define eps 1e-11
using namespace std;

ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double x;
        scanf("%lf",&x);
        ll fz=(ll)((x+eps)*1000000000);
        ll fm=1000000000;
        ll tep=gcd(fz,fm);
        printf("%I64d/%I64d\n",fz/tep,fm/tep);
    }
    return 0;
}



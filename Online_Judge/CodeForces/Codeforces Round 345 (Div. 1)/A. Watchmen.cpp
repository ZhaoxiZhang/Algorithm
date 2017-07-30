#include<bits/stdc++.h>
using namespace std;

int  main()
{
    map<int, int>x;
    map<int, int>y;
    map<pair<int,int>, int>cross;
    int n;
    long long res = 0;
    scanf("%d", &n);
    while(n--)
    {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        res += x[xx]++;
        res += y[yy]++;
        res -= cross[make_pair(xx,yy)]++;
    }
    cout << res << endl;
    return 0;
}

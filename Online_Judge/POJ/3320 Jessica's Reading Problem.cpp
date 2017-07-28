#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set>
#include<map>
using namespace std;
int ans[1000005] = {0};
int main()
{
    set<int>all;
    map<int,int>cnt;
    int P;
    scanf("%d",&P);
    for (int i = 0;i < P;i++)
    {
        scanf("%d",&ans[i]);
        all.insert(ans[i]);
    }
    int n = all.size();
    int t = 0,s = 0,num = 0,res = P;
    for (;;)
    {
        while (num < n && t < P)
        {
            if (cnt[ans[t++]]++ == 0)
            {
                num++;
            }
        }
        if (num < n) break;
        res = min(res, t-s);
        if (--cnt[ans[s++]] == 0)
        {
            num--;
        }
    }
    printf("%d\n",res);
    return 0;
}

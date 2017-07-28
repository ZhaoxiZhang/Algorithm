#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    int cas = 0;
    while (T--)
    {
        if (cas)
        {
            printf("\n");
        }
        vector<int>itv;
        vector<int>::iterator it;
        int N,tmp,i;
        scanf("%d",&N);
        for (i = 0;i < N;i++)
        {
            scanf("%d",&tmp);
            itv.push_back(tmp); 
        }
        int max,sum = 0,left = 0,right = 0;
        tmp = 0;
        for (it = itv.begin(),i = 0;it != itv.end();it++,i++)
        {
            sum += *it;
            if (i == 0)
            {
                max = sum;
            }
            if (sum > max)
            {
                max = sum;
                right = i;
                left = tmp;
            }
            if (sum < 0)
            {
                sum = 0;
                tmp = i+1;
            }
        }
        printf("Case %d:\n%d %d %d\n",++cas,max,left+1,right+1);
    }
    return 0;
} 

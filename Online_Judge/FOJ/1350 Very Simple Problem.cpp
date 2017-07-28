#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn = 110;
using namespace std;
int main()
{
    int n,p,i,j;
    int rate[maxn];
    while (~scanf("%d%d",&n,&p)){
        int min_n[maxn]={0},max_n[maxn]={0};
        for (i = 0;i < n;i++){
            for (j = 0;j < p;j++)
                scanf("%d",&rate[j]);
            int min1 = rate[0],max1 = rate[0];
            for (j = 0;j < p;j++)
                min1 = min(min1,rate[j]),max1 = max(max1,rate[j]);
            for (j = 0;j < p;j++){
                if (rate[j] == min1)
                    min_n[j]++;
                if (rate[j] == max1)
                    max_n[j]++;
            }
        }
        bool flag = false,first = true;
        for (i = 0;i < p;i++)
            if (min_n[i] > n/2 && !max_n[i]){
                first?printf("%d",i+1):printf(" %d",i+1);
                flag = true,first = false;
            }
        if (!flag)  
            printf("0");
        printf("\n");
    }
    return 0;
}

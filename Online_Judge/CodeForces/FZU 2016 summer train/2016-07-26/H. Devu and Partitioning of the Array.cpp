#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int n,k,p;
    while (~scanf("%d%d%d",&n,&k,&p))
    {
        int tmp;
        vector<int>itv1,itv2;
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&tmp);
            if (tmp & 1)
            {
                itv1.push_back(tmp);
            }
            else
            {
                itv2.push_back(tmp);
            }
        }
        int len1 = itv1.size();
        int len2 = itv2.size();
        if (len1 < (k - p) || ((len1 - (k - p))&1) || ((len1 - (k - p))/2 + len2 < p))
        {
            printf("NO\n");
        }
        else
        {
            int x = k - p;
            printf("YES\n");
            for (int i = 0;i < x - 1;i++)
            {
            	printf("1 %d\n",itv1.back());
            	itv1.pop_back();
            }
            for (int i = 0;i < p - 1;i++)
            {
            	if (!itv2.empty())
            	{
            		printf("1 %d\n",itv2.back());
            		itv2.pop_back();
            	}
            	else
            	{
            		printf("2");
            		for (int j = 0;j < 2;j++)
					{
						printf(" %d",itv1.back());
						itv1.pop_back();
					} 
					printf("\n");
            	}
            }
            if (x && p)
            {
            	printf("1 %d\n",itv1.back());
            	itv1.pop_back();
            }
            printf("%d",itv1.size()+itv2.size());
            while (!itv1.empty())
            {
            	printf(" %d",itv1.back());
            	itv1.pop_back();
            }
            while (!itv2.empty())
            {
            	printf(" %d",itv2.back());
            	itv2.pop_back();
            }
            printf("\n");
        }
    }
    return 0;
}


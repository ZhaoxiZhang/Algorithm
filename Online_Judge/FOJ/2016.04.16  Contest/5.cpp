#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
int ans[100005];
int hash[100005];
int value[100005];

/*bool cmp(int x,int y)
{
    if (x < y)
    {
        return (x > y);
    }
    else
    {
        return (x > y);
    }
}*/

int main()
{
    int N;

    while (scanf("%d",&N) != EOF)
    {
        memset(ans,0,sizeof(ans));
        
        for (int i = 1; i <= N; i++)
        {
            scanf("%d",&ans[i]);
        }

        int q;
        scanf("%d",&q);
        while (q--)
        {
            int L,R;
            int sum = 0,max= 0;
            map<int,int>pos1;
        	map<int,int>pos2;
        	memset(hash,0,sizeof(hash));
        	memset(value,0,sizeof(value));

            scanf("%d%d",&L,&R);

            for (int i = L; i <= R; i++)
            {
                ++hash[ans[i]];
                if (hash[ans[i]] == 1)
                {
                    pos1[ans[i]] = i;
                }
                if (hash[ans[i]] > 1)
                {
					pos2[ans[i]] = i;
                	sum  = pos2[ans[i]] - pos1[ans[i]];
                	
                	if (sum > max)
                	{
                		max = sum;
                	}
                }
            }

            printf("%d\n",max);
        }
    }

    return 0;
}


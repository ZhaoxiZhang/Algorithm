#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    char str[100];
    int ans[100],K,maxx,pos;
    memset(str,0,sizeof(str));
    memset(ans,0,sizeof(ans));
    while(~scanf("%s %d",str,&K))
    {
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            ans[i] = str[i] - '0';
        }
        bool flag = false;
        for (int i = 0; i < len; i++)
        {
            if (!K)
                break;
            maxx = 0;
            for (int j = i; j <= i + K && j < len; j++)
            {
                if (maxx < ans[j])
                {
                    maxx = ans[j];
                    pos = j;
                    flag = true;
                }
            }
            for (int j = pos; j > i; j--)
            {
                int tmp = ans[j];
                ans[j] = ans[j-1];
                ans[j-1] = tmp;
            }
            if (flag)
			{
				K = K - (pos - i);
				flag = false;
			}
        }
        for (int i = 0; i < len; i++)
        {
            printf("%d",ans[i]);
        }
        printf("\n");
        memset(str,0,sizeof(str));
        memset(ans,0,sizeof(ans));
    }
    return 0;
}


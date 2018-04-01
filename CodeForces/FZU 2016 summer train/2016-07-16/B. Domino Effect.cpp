#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int N;
    char str[3005];
    int ans[3005];
    bool flag = true,IsL = false;
    memset(str,0,sizeof(str));
    memset(ans,0,sizeof(ans));
    scanf("%d",&N);
    scanf("%s",str);
    for (int i = 0; i < N; i++)
    {
        if (str[i] == 'L' || str[i] == 'R')
        {
            flag = false;
            if (str[i] == 'L')
            {
                IsL = true;
                break;
            }
            else
            {
            	if (str[i] == 'R')
            	{
            		IsL = false;
            		break;
            	}
            }
        }
    }
    int j = 0,sum = 0,len = 0;
    for (int i = 0; i < N; i++)
    {
        if (str[i] == '.')
        {
            continue;
        }
        else
        {
            ans[j++] = i;
        }
    }
    if (flag)
    {
        printf("%d\n",N);
    }
    else
    {
        len = j;
        sum = 0;
        if (IsL)
        {
            for (int i = 0; i < len - 1; i++)
            {
                if (i%2==0)
                {
                    sum += (ans[i+1]-ans[i]-1);
                }
                else if (i&1)
                {
                    if ((ans[i+1]-ans[i])%2 == 0)
                    {
                        sum++;
                    }
                }
            }
            if (str[ans[len-1]] == 'L')
            {
                sum += (N-ans[len-1]-1);
            }
        }
        else
        {
            sum += ans[0];
            for (int i = 0; i < len - 1; i++)
            {
                if (i&1)
                {
                    sum += (ans[i+1] - ans[i] - 1);
                }
                else if (i % 2 == 0)
                {
                    if ((ans[i+1]-ans[i])%2 == 0)
                    {
                        sum++;
                    }
                }
            }
            if (str[ans[len-1]] == 'L')
            {
                sum += (N-ans[len-1]-1);
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}

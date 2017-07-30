#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    int tmp;
    int ans[100005];
    bool flag = true,noa = false;
    vector<int>all,A,B;
    vector<int>::iterator it;
    vector<int>::iterator itt;
    memset(ans,0,sizeof(ans));
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&tmp);
        all.push_back(tmp);
    }
    int cnt = 0;
    for (it = all.begin(); it != all.end(); it++)
    {
        tmp = a - *it;
        itt = find(all.begin(),all.end(),tmp);
        if (itt != all.end())
        {
            A.push_back(*it);
        }
        else
        {
            B.push_back(*it);
            ans[cnt] = 1;
        }
        cnt++;
    }
    /*for (it = A.begin(); it != A.end(); it++)
    {
        printf("%d ",*it);
    }
    printf("\n");
    cout << "OK" << endl;
    for (it = B.begin(); it != B.end(); it++)
    {
        printf("%d ",*it);
    }
    printf("\n");*/
    for (it = B.begin(); it != B.end(); it++)
    {
        tmp = b - *it;
        //printf("%d\n",tmp);
        itt = find(B.begin(),B.end(),tmp);
        if (itt == B.end())
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        printf("YES\n");
        bool first = true;
        for (int i = 0; i < cnt; i++)
        {
            first?printf("%d",ans[i]):printf(" %d",ans[i]);
            first = false;
        }
        printf("\n");
    }
    else if (!flag)
    {
        A.clear();
        B.clear();
        memset(ans,0,sizeof(ans));
        int cnt = 0;
        for (it = all.begin(); it != all.end(); it++)
        {
            tmp = b - *it;
            itt = find(all.begin(),all.end(),tmp);
            if (itt != all.end())
            {
                B.push_back(*it);
                ans[cnt] = 1;
            }
            else
            {
                A.push_back(*it);
            }
            cnt++;
        }
        for (it = A.begin(); it != A.end(); it++)
        {
            tmp = a - *it;
            itt = find(A.begin(),A.end(),tmp);
            if (itt == A.end())
            {
                noa = true;
                break;
            }
        }
        if (!noa)
        {
            printf("YES\n");
            bool first = true;
            for (int i = 0; i < cnt; i++)
            {
                first?printf("%d",ans[i]):printf(" %d",ans[i]);
                first = false;
            }
            printf("\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}


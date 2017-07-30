#include<bits/stdc++.h>
using namespace std;
const int maxn = 300005;
char str[maxn];

int main()
{ 
	freopen("input.txt","r",stdin); 
	int n,m,pos,dot = 0,segment = 0;
    char ch;
    scanf("%d%d",&n,&m);
    scanf("%s",str);
    for (int i = 0;i < n;i++)
    {
        if (str[i] == '.')  dot++;
        if (str[i] == '.' && (!i || str[i-1] != '.'))   segment++;
    }
    for (int i = 0;i < m;i++)
    {
        scanf("%d %c",&pos,&ch);
        pos--;
        if (ch != '.')
        {
            if (str[pos] == '.')
            {
                dot--;
                if (!pos && str[pos + 1] != '.')    segment--;
                else if (pos == n - 1 && str[pos - 1] != '.')    segment--;
                else if (pos && pos < n - 1 && str[pos - 1] == '.' && str[pos + 1] == '.')  segment++;
                else if (pos && pos < n - 1 && str[pos - 1] != '.' && str[pos + 1] != '.')  segment--;
            }
            str[pos] = ch;
        }
        else
        {
            if (str[pos] != '.')
            {
                dot++;
                if (!pos && str[pos + 1] != '.')    segment++;
                else if (pos == n - 1 && str[pos - 1] != '.')    segment++;
                else if (pos && pos < n - 1 && str[pos - 1] == '.' && str[pos + 1] == '.')  segment--;
                else if (pos && pos < n - 1 && str[pos - 1] != '.' && str[pos + 1] != '.')  segment++;
            }
            str[pos] = ch;
        }
        printf("%d\n",dot - segment);
    }
    return 0;
}

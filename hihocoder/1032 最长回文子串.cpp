#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
char str[maxn],s[maxn<<1];
int p[maxn<<1];

void Manacher(int len)
{
    int pos = 0;
    s[pos++] = '$';
    s[pos++] = '#';
    for (int i = 0;i < len;i++)
    {
        s[pos++] = str[i];
        s[pos++] = '#';
    }
    s[pos] = 0;
    int mx = 0,id = 0;
    for (int i = 0;i < pos;i++)
    {
        p[i] = mx>i?min(p[2*id-i],mx-i):1;
        while (s[i+p[i]] == s[i-p[i]])  p[i]++;
        if (i + p[i] > mx)
        {
            mx = i + p[i];
            id = i;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        memset(str,0,sizeof(str));
		memset(s,0,sizeof(s));
        memset(p,0,sizeof(p));
        int res = 0;
        scanf("%s",str);
        int len = strlen(str);
        Manacher(len); 
        for (int i = 0;i < 2*len + 2;i++)   res = max(res,p[i] - 1);
            printf("%d\n",res);
    }
    return 0;
}

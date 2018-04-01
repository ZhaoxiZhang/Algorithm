#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;
char str[maxn];

int main()
{
    int sum = 0;
    scanf("%s",str);
    int len = strlen(str);
    for (int i = 0;i < len/2;i++)
    {
        if (str[i] != str[len - i -1])	sum++;
    }
    if (sum == 0 && (len%2) == 1)	printf("YES\n");
    else if (sum == 1)	printf("YES\n");
    else	printf("NO\n");
    return 0;
} 

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;

int main()
{
	char str[100005];
	LL ans[300];
	memset(str,0,sizeof(str));
	memset(ans,0,sizeof(ans));
	scanf("%s",str);
	
		LL sum = 0;
		int len = strlen(str);
		for (int i = 0;i < len;i++)
		{
			ans[str[i]]++;
		}
		for (int i = 0;i <= 256;i++)
		{
			sum += ans[i]*ans[i];
		}
		printf("%I64d\n",sum);
		
	
	return 0;
}

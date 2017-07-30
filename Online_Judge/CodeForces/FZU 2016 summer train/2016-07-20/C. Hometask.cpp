#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int k,cnt1 = 0,cnt2 = 0,res = 0;
	char str[100005],tmp[5];
	memset(str,0,sizeof(str));
	memset(tmp,0,sizeof(tmp));
	scanf("%s",str);
	scanf("%d",&k);
	int len = strlen(str);
	while (k--)
	{
		scanf("%s",tmp);
		cnt1 = cnt2 = 0;
		for (int i = 0;i < len;i++)
		{
			if (str[i] == tmp[0])
			{
				cnt1++;
			}
			else if (str[i] == tmp[1])
			{
				cnt2++;
			}
			else
			{
				res += min(cnt1,cnt2);
				cnt1 = 0;
				cnt2 = 0;
			}
		}
		res += min(cnt1,cnt2);
	}
	printf("%d\n",res);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int INF = (1<<30)-1;
const int maxn = 55;
char str[maxn][maxn];
char tmp[maxn],tmp1[maxn];

int main()
{
	freopen("input.txt","r",stdin);
	int n,res = INF;
	bool flag = false,success = true;
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		scanf("%s",str[i]);
	}
	int len = strlen(str[0]);
	for (int i = 0;i < n;i++)
	{
		int cnt = 0;
		for (int j = 0;j < n;j++)
		{
			if (i == j)
			{
				flag = true;
				continue;
			}
			flag = false;
			if (strcmp(str[j],str[i]) == 0)
			{
				flag = true;
				continue;
			}
			strcpy(tmp1,str[j]);
			int tmplen = len;

			while (--tmplen)
			{
				strncpy(tmp,tmp1+1,len-1);
				tmp[len - 1] = tmp1[0];
				cnt++;
				strcpy(tmp1,tmp);
				if (strcmp(tmp1,str[i]) == 0)
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				success = false;
				break;
			}
		}
		if (!flag)
		{
			success = false;
			break;
		}
		res = min(res,cnt);
	}
	if (!success)	printf("-1\n");
	else	printf("%d\n",res);
	return 0;
}

#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100005;
char a[maxn];

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		__int64 res = 0,cnt = 0;
		scanf("%s",a);
		int len = strlen(a);
		for (int i = 0;i < len;)
		{
			if (a[i] == 'q')
			{
				while (a[i] == 'q')
				{
					i++;
					cnt++;
				}
				res += (1+cnt)*cnt/2;
				cnt = 0;
			}
			else
			{
				i++;
			}
		}
		printf("%I64d\n",res);
	}
	return 0;
}

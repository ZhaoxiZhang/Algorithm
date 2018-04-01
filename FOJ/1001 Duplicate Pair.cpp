#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		char str[1000005];
		memset(str,0,sizeof(str));
		int tmp,record;
		while (n--)
		{
			scanf("%d",&tmp);
			if (str[tmp])
			{
				record = tmp;
			}
			else
			{
				str[tmp] = 1;
			}
		}
		printf("%d\n",record);
	}
	return 0;
} 

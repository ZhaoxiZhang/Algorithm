#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n,m;
	char str[200005],ans[30];
	char tmp1,tmp2;
	scanf("%d%d",&n,&m);
	scanf("%s",str);
	for (int i = 0;i < 26;i++)
	{
		ans[i] = i + 97;
	}
	while (m--)
	{
		getchar();
		scanf("%c %c",&tmp1,&tmp2);
		if (tmp1 == tmp2)
		{
			continue;
		}
		for (int i = 0;i < 26;i++)
		{
			if (ans[i] == tmp1)
			{
				ans[i] = tmp2;
			}
			else if(ans[i] == tmp2)
			{
				ans[i] = tmp1;
			}
		}
	}
	for (int i = 0;i < n;i++)
	{
		printf("%c",ans[str[i] - 97]);
	}
	printf("\n");
	return 0;
}

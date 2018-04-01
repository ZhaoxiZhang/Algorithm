#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ans[1005][1001] = {{'0'},{'1'},{'1'}};
//char str[1001][1001] = {0};
int main()
{
	int n;
	//printf("%s %s\n",ans[1],ans[2]);
	//printf("%c\n",ans[1][0]);
	while (scanf("%d",&n) != EOF)
	{
		int i,j;
		for (i = 3;i <= n;i++)
		{
			//int len1 = strlen(ans[i - 1]);
			//int len2 = strlen(ans[i - 2]);
			//int min = (len1 <= len2) ? len1 : len2;
			//int max = (len1 >= len2) ? len1 : len2;
			strrev(ans[i - 1]);
			strrev(ans[i - 2]);
			//strcpy(str[i],ans[i - 1]);
			for (j = 0;ans[i - 1][j]&&ans[i - 2][j];j++)
			{
				ans[i][j] = ans[i - 1][j] + ans[i - 2][j] - 48;
				//printf("%c\n",ans[i][j]);
				ans[i][j] %= 10;
				ans[i + 1][j]+= (ans[i][j]/10);
				printf("OK\n");
				printf("%c\n",ans[i][j]);
			}
			while(ans[i - 1][j])
			{
				ans[i][j] += ans[i - 1][j];
				ans[i][j] %= 10;
				ans[i + 1][j] /=10;
				j++;
			}
			while (ans[i - 2][j])
			{
				ans[i][j] += ans[i - 2][j];
				ans[i][j] %= 10;
				ans[i + 1][j] /=10;
				j++;
			}
			if (ans[i][j] == 1)
			{
				ans[i][j] += 48;
			}
		}
		printf("%s\n",ans[n]);
	}
	return 0;
} 

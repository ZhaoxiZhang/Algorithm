#include<stdio.h>
#include<string.h>
const int maxn = 1005;
int dp[maxn][maxn] = {0};
int main()
{
	char a[maxn],b[maxn],lcs[maxn];
	int i,j;
	scanf("%s",a);scanf("%s",b);
	int lena = strlen(a),lenb = strlen(b);
	for (i = 1;i <= lena;i++)
	{
		for (j = 1;j <= lenb;j++)
		{
			if (a[i-1] == b[j-1])	dp[i][j] = dp[i-1][j-1]+1;
			else	dp[i][j] = dp[i][j-1]>dp[i-1][j]?dp[i][j-1]:dp[i-1][j];
		}
	}
	i = lena,j = lenb;
	int len = dp[lena][lenb];
	lcs[len] = '\0';
	while (dp[i][j])
	{
		if (dp[i][j] == dp[i-1][j])	i--;
		else if (dp[i][j] == dp[i][j-1])	j--;
		else lcs[--len] = a[i-1],i--,j--;
	}
	printf("%s\n",lcs);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
char s[maxn],res[maxn];
int num[maxn];

bool check(int n)
{
	for (int i = 0;i < n / 2;)
	{
		if (num[i] == num[n - i - 1])	i++;
		else if ((num[i] == num[n - i - 1] + 1) || (num[i] == num[n - i - 1] + 11))  //来自低位的进位 
		{
			num[i]--;
			num[i + 1] += 10;
		}
		else if (num[i] == num[n - i - 1] + 10)     //来自高位的退位 
		{
			num[n - i - 2]--;
			num[n - i - 1] += 10;
		}
		else	return false;
	}
	if (n % 2 == 1)
	{
		if ((num[n/2]%2 == 1) || (num[n/2] > 18) || (num[n/2] < 0))	return false;
		else	res[n/2] = num[n/2]/2 + '0';	
	} 
	for (int i = 0;i < n / 2;i++)
	{
		if (num[i] > 18 || num[i] < 0)	return false;
		res[i] = (num[i] + 1) / 2 + '0';
		res[n - i - 1] = num[i] / 2 + '0';
	}
	return res[0] > '0';
}


int main()
{
	scanf("%s",s);
	int len = strlen(s);
	for (int i = 0;i < len;i++)	num[i] = s[i] - '0';
	if (check(len))	puts(res);
	else if (s[0] == '1' && len > 1)
	{
		for (int i = 0;i < len;i++)	num[i] = s[i + 1] - '0';
		len--;
		num[0] += 10;
		if (check(len))	puts(res);
		else	puts("0"); 
	}
	else	puts("0");
	return 0;
}

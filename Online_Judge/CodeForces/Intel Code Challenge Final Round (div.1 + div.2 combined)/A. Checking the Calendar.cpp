#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x,y;
	int a[5] = {29,31,32};
	string str1,str2;
	cin >> str1 >> str2;
	if (str1 == "monday")	x = 1;		if (str2 == "monday")	y = 1;
	if (str1 == "tuesday")	x = 2;		if (str2 == "tuesday")	y = 2;
	if (str1 == "wednesday")	x = 3;	if (str2 == "wednesday")	y = 3;
	if (str1 == "thursday")	x = 4;		if (str2 == "thursday")	y = 4;
	if (str1 == "friday")	x = 5;		if (str2 == "friday")	y = 5;
	if (str1 == "saturday")	x = 6;		if (str2 == "saturday")	y = 6;
	if (str1 == "sunday")	x = 7;		if (str2 == "sunday")	y = 7;
	bool flag = false;
	if (y >= x)
	{
		for (int i = 0;i < 3;i++)
		{
			if (a[i] % 7 == y - x + 1) 
			{
				flag = true;
				break;
			}
		}
		if (flag)	printf("YES\n");
		else	printf("NO\n");
	}
	else
	{
		for (int i = 0;i < 3;i++)
		{
			if (a[i] % 7 == 7 - x + 1 + y)
			{
				flag = true;
				break;
			}
		}
		if (flag)	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}

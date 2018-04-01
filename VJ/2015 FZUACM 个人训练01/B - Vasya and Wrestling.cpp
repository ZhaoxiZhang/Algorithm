#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<sstream>
using namespace std;

int main()
{
	int N;
	bool flag;
	string str1,str2,tmp;
	scanf("%d",&N);
	__int64 scores,sum1 = 0,sum2 = 0;
	stringstream ss;
	while (N--)
	{
		scanf("%I64d",&scores);
		if (N == 0)
		{ 
			if (scores > 0)
			{
				flag = true;
			}
			else if (scores < 0)
			{
				flag = false;
			}
		} 
		if (scores > 0)
		{
			sum1 += scores;
			ss << scores;
			ss >> tmp;
			str1 += tmp;
			ss.clear();
		}
		else if (scores < 0)
		{
			scores = -scores;
			sum2 += scores;
			ss << scores;
			ss >> tmp;
			str2 += tmp;
			ss.clear();
		}
	}
	if (sum1 > sum2)
	{
		printf("first\n");
	} 
	else if (sum1 < sum2)
	{
		printf("second\n");
	}
	else if (sum1 == sum2)
	{
		if (str1 > str2)
		{
			printf("first\n");
		}
		else if (str1 < str2)
		{
			printf("second\n");
		}
		else if (str1 == str2)
		{
			if (flag)
			{
				printf("first\n");
			}
			else
			{
				printf("second\n");
			}
		}
	}
	return 0;
}

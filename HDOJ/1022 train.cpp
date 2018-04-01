#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int maxn = 15;
int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		bool flag = true;
		stack<int>stk;
		int i,inout[maxn] = {0},in[maxn],out[maxn];
		char sin[maxn],sout[maxn];
		scanf("%s %s",sin,sout);
		for (i = 0;i < N;i++)	in[i] = sin[i] - '0';
		for (i = 0;i < N;i++)	out[i] = sout[i] - '0';
		int j = 0,p = 0;
		i = 0;
		for (i = 0;i < N;i++)
		{
			if (in[i] != out[j])
			{
				inout[p++] = 0;
				stk.push(in[i]);
			}
			else if (in[i] == out[j])
			{
				inout[p++] = 0;
				j++;
				inout[p++] = 1;
				while (!stk.empty() && stk.top() == out[j])
				{
					j++;
					inout[p++] = 1;
					stk.pop();
				}
			}
		}
		while (!stk.empty())
		{
			if (stk.top() != out[j])
			{
				flag = false;
				break;
			}
			else
			{
				j++;
				stk.pop();
				inout[p++] = 1;
			}
		}
		if (!flag)	printf("No.\nFINISH\n");
		else
		{
			printf("Yes.\n");
			for (i = 0;i < p;i++)	inout[i]?printf("out\n"):printf("in\n");
			printf("FINISH\n");
		}
	}
	return 0;
}

/*
5
12342 24321
*/

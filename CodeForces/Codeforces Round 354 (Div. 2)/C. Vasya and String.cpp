#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
char str[maxn];
bool flag[maxn];

int main()
{
	//freopen("input.txt","r",stdin);
	int n,k,res = 0;
	memset(flag,false,sizeof(flag));
	queue<int>que1,que2;
	scanf("%d%d%s",&n,&k,str);
	int len = strlen(str);
	int s = 0,t = 0,sum = 0;
	for (;;)
	{
		if (t >= len)	break;
		while (t < len && sum <= k)
		{
			if (str[t] == 'b')
			{
				if (!flag[t])	flag[t] = true,que1.push(t);
				t++,sum++;
			}	
			else	t++;
		}
		if (sum > k)	sum--,t--;
		if (t > len)	break;
		res = max(res,t - s);
		sum--;
		s = que1.front()+1;
		que1.pop();
	}
	s = 0,t = 0,sum = 0;
	memset(flag,false,sizeof(flag));
	for (;;)
	{
		if (t >= len)	break;
		while (t < len && sum <= k)
		{
			if (str[t] == 'a')
			{
				if (!flag[t])	flag[t] = true,que2.push(t);
				t++,sum++;
				
			}
			else	t++;
		}
		if (sum > k)	sum--,t--;
		if (t > len)	break;
		res = max(res,t - s);
		sum--;
		s = que2.front()+1;
		que2.pop();
	}
	printf("%d\n",res);
	return 0;
}

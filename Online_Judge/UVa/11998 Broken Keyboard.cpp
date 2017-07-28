#include<bits/stdc++.h>
using namespace std;
char str[100010];
int main()
{
	while(scanf("%s",str)!=EOF)
	{
		deque<int > q;
		int i=0;
		while(str[i]=='['||str[i]==']')  i++;
		q.push_front(i);
		while(str[i])
		{
			if(str[i]=='[')
			{
				q.push_front(i+1);
				str[i]='\0';
			}
			else if(str[i]==']')
			{
				q.push_back(i+1);
				str[i]='\0';
			}
			i++;
		}
		while(!q.empty())
		{
			printf("%s",str+q.front());
			q.pop_front();
		}
		printf("\n");

	}
	return 0;
}

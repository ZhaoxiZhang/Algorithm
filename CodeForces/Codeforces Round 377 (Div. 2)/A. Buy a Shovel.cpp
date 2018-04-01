#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k,r;
	scanf("%d%d",&k,&r);
	for (int i = 1;;i++)
	{
		if ((i*k-r)%10 == 0||i*k%10 == 0)
		{
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}

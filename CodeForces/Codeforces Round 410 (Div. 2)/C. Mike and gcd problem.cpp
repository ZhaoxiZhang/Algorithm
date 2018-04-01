#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}

int main()
{
	int n,res = 0,resgcd = 0,cnt = 0,tmp;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d",&tmp);
		resgcd = gcd(resgcd,tmp);
		if (tmp&1)	cnt++;
		else	res += (cnt/2) + 2*(cnt&1),cnt = 0;
	}
	res += (cnt/2) +2*(cnt&1);
	printf("YES\n");
	if (resgcd > 1)	printf("0\n");
	else	printf("%d\n",res);
	return 0;
}

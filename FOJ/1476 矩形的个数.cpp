#include<cstdio>
using namespace std;
typedef __int64 LL;
int main()
{
	LL A,B;
	
	while (~scanf("%I64d%I64d",&A,&B))
	{
		LL sum;
		sum = (1 + A) * A /2 *(1 + B) * B /2;
		printf("%I64d\n",sum);
	}
	return 0;
} 

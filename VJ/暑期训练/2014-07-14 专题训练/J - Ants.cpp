#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAX_N=1000005;
int xi[MAX_N];
int main()
{
	int T,L,n,i;
	scanf("%d",&T);
	while(T--)
	{
		int minT=0,maxT=0;
		scanf("%d%d",&L,&n);
		for(i=0;i<n;i++)
		    scanf("%d",&xi[i]);
		for(i=0;i<n;i++)
		    minT=max(minT,min(xi[i],L-xi[i]));
		for(i=0;i<n;i++)
		    maxT=max(maxT,max(xi[i],L-xi[i]));
		printf("%d %d\n",minT,maxT);
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N,Q,x,p,maxx,pos,id,sum[maxn] = {0};
		bool flag = true;
		scanf("%d%d",&N,&Q);
		scanf("%d%d",&x,&p);
		sum[x] = p;
		maxx = p;
		pos = 0;
		id = x;
		for (int i = 1;i < Q;i++)
		{
			scanf("%d%d",&x,&p);
			sum[x] += p;
			if (sum[x] > maxx )
			{
				maxx = sum[x];
				if (id != x)	flag = false,id = x,pos = i;
			}
			else if (sum[x] == maxx && id > x)
			{
				flag = false;
				pos = i;
				id = x;
			}
 		}
		if (flag)	printf("0\n");
		else	printf("%d\n",pos + 1);
	}
	return 0;
}
 

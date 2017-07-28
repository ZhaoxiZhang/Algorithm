#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;
const long long  INF = (1LL << 31);
struct node{
	LL a,b,c;
};
node p[20005];
int N;

bool OK(LL x)
{
	LL sum = 0,tmp = 0;
	for (int i = 0;i < N;i++)
	{
		tmp = min(x,p[i].b);
		if (tmp >= p[i].a)
		{
			sum += (tmp - p[i].a)/p[i].c + 1;
		}
	}
	if (sum & 1)
		return true;
	else
		return false;
}

int main()
{
	while (~scanf("%d",&N))
	{
		LL maxx = 0,minn = INF,sum = 0;
		memset(p,0,sizeof(p));
		for (int i = 0;i < N;i++)
		{
			scanf("%I64d%I64d%I64d",&p[i].a,&p[i].b,&p[i].c);
			maxx = max(maxx,p[i].b);
			minn = min(minn,p[i].a);
			sum += (p[i].b - p[i].a)/p[i].c + 1;
		}
		//cout << minn << " " << maxx << endl;
		if (!(sum & 1))
		{
			printf("DC Qiang is unhappy.\n");
			continue;
		}
		LL left = minn,right = maxx;
		while (left < right)
		{
			LL mid = left +((right-left)>>1);
			if (OK(mid))
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		//cout << left << " " << right << endl;
		LL cnt = 0;
		for (int i = 0;i < N;i++)
		{
			if (right >= p[i].a && right <= p[i].b && (right - p[i].a) % p[i].c == 0)
			{
				cnt++;
			}
		}
		printf("%I64d %I64d\n",right,cnt);
	} 
	return 0;
}

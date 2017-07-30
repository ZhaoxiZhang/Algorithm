#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;
const int maxn = 200005;
set<int>sw,sh;
set<int>::iterator font,rear;
int w[maxn],h[maxn];

void solve(set<int>&s,int *a,int p)
{
	s.insert(p);
	font = rear = s.find(p);
	font--;rear++;
	--a[*rear - * font];
	++a[p - *font];
	++a[*rear - p];
}

int main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int ww,hh,n,tmp;
	char hv[5];
	memset(w,0,sizeof(w));
	memset(h,0,sizeof(h));
	scanf("%d%d%d",&ww,&hh,&n);
	sw.insert(0),sh.insert(0);
	sw.insert(ww),sh.insert(hh);
	h[0] = h[hh] = 1;
	w[0] = w[ww] = 1;
	int maxw = ww,maxh = hh;
	while (n--)
	{
		scanf("%s %d",hv,&tmp);
		if (hv[0] == 'H')	solve(sh,h,tmp);
		else	solve(sw,w,tmp);
		while (!w[maxw])	maxw--;
		while (!h[maxh])	maxh--;
		printf("%I64d\n",LL(maxw)*LL(maxh));
	}
	return 0;
}

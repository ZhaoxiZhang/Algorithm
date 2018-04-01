#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;
const int maxn = 100005;
LL a[maxn],sum[maxn];
multiset<int>pos;
multiset<LL>s;
multiset<int>::iterator front,rear;
multiset<LL>::iterator it; 

int main()
{
	int n,p;
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		scanf("%I64d",&a[i]);
		sum[i+1] = sum[i] + a[i];
	}
	sum[n+1] = sum[n];
	pos.insert(0),pos.insert(n+1);
	s.insert(sum[n]);
	while (n--)
	{
		scanf("%d",&p);
		pos.insert(p);
		front = rear = pos.find(p);
		front--,rear++;
		s.erase(s.find(sum[*rear-1]-sum[*front]));
		s.insert(sum[*rear-1]-sum[p]);
		s.insert(sum[p-1]-sum[*front]);
		it = s.end();
		--it--;
		cout << *it << endl;
	}
	return 0;
}

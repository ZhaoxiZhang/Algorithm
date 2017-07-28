#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 200005;
int N,root[maxn],a[maxn],c[maxn];

int find(int x)
{
	if (root[x] != x)	root[x] = find(root[x]);
	return root[x];
} 

int find_kth(int x) //查找第k小的元素 
{
	int ans = 0,cnt = 0;
	for (int i = 20;i >= 0;i--)   //这里的20适当的取值，与MAX_VAL有关，一般取lg(MAX_VAL)
	{
		ans += (1 << i);
		if (ans > N || cnt + c[ans] >= x)
			ans -= (1 << i);
		else
			cnt += c[ans]; 
	}
	return ans + 1;
}

void upd(int i,int v)
{
	while (i <= N)
	{
		c[i] += v;
		i += i & -i; 
	}
}

int main()
{
	int M;
	while (~scanf("%d%d",&N,&M))
	{
		int tot = N;
		memset(c,0,sizeof(c));
		for (int i = 1;i <= N;i++)	root[i] = i,a[i] = 1; //a[i]表示编号为i的Group大小 
		upd(1,N);                //初始Group大小为1的有N个 
		while (M--)
		{
			int opt,x,y;
			scanf("%d",&opt);
			if (opt == 0)
			{
				scanf("%d%d",&x,&y);
				x = find(x);
				y = find(y);
				if (x == y)	continue;
				upd(a[x],-1);
				upd(a[y],-1);       //x与y合并，则编号为x的Group与编号为y的Group大小减1
				upd(a[x] + a[y],1); //大小为a[x]+a[y]的Group的大小增1 
				root[y] = x;        //y的祖先节点为x；
				a[x] += a[y];       //编号为x的Group大小增加a[y]
				tot--;              //并查集合并，则总元素减少1 
			}
			else
			{
				scanf("%d",&x);
				printf("%d\n",find_kth(x)); 
			}
		}
	}
	return 0;
}

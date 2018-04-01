#include<stdio.h>
#include<string.h>
const int maxn = 1005;
struct Node{
	int x,y;
}node[maxn];
int N,d,fa[maxn];
bool repair[maxn];

int find(int x)
{
	int r = x;
	while (r != fa[r])	r = fa[r];
	int i = x,j;
	while (i != r)
	{
		j = fa[i];
		fa[i] = r;
		i = j;
	}
	return r;
}

void unite(int x,int y)
{
	x = find(x),y = find(y);
	if (x != y)	fa[x] = y;
}

bool dist(struct Node xx,struct Node yy)
{
	return	((xx.x-yy.x)*(xx.x-yy.x)+(xx.y-yy.y)*(xx.y-yy.y)) <= d*d;
	
}

int main()
{
	int index,index1,index2;
	char op[5];
	memset(repair,false,sizeof(repair));
	scanf("%d%d",&N,&d);
	for (int i = 1;i <= N;i++)
	{
		fa[i] = i;
		scanf("%d%d",&node[i].x,&node[i].y);
	}
	while (~scanf("%s",op))
	{
		if (op[0] == 'O')
		{
			scanf("%d",&index);
			repair[index] = true;
			for (int i = 1;i <= N;i++)
			{
				if (i != index && repair[i] && dist(node[i],node[index]))	unite(i,index);
			}
		}
		else if (op[0] == 'S')
		{
			scanf("%d%d",&index1,&index2);
			index1 = find(index1),index2 = find(index2);
			if (index1 == index2)	printf("SUCCESS\n");
			else	printf("FAIL\n");
		}
	}
	return 0;
}

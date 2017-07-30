#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int father[105];
int rk[105];
int N,M;

void init()
{
    memset(father,0,sizeof(father));
    memset(rk,0,sizeof(rk));
    for (int i = 0; i <= N; i++)
    {
        father[i] = i;
    }
}

int find(int x)
{
    int r = x;
    while (father[r] != r)
    {
        r = father[r];
    }
    int i = x,j;
    while (i != r)
    {
        j = father[i];
        father[i] = r;
        i = j;
    }
    return r;
}


void unite(int x,int y)
{
    int fx,fy;
    fx = find(x);
    fy = find(y);
    if (fx == fy)   return;
    if (rk[fx] < rk[fy])
    {
        father[fx] = fy;
    }
    else
    {
        father[fy] = fx;
        if (rk[fx] == rk[fy])
        {
            rk[fx]++;
        }
    }

}

int main()
{

	while (~scanf("%d%d",&N,&M))
	{
		int x,y,res = 0;
		init();
		while (M--)
		{
			 scanf("%d%d",&x,&y);
			 x = find(x);
			 y = find(y);
			 if (x == y)
			 {
			 	res++;
			 }
			 else
			 {
			 	father[x] = y;
			 }
		}
		x = find(1);
		for (int i = 2;i <= N;i++)
		{
			if (find(i) != x)
			{
				res = 2;
				break;
			}
		}
		if (res == 1)
		{
			printf("FHTAGN!\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
} 

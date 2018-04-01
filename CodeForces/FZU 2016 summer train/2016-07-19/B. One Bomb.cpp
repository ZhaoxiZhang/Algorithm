#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,M;
int r[1005],c[1005];
char maze[1005][1005];
int cnt = 0;   
bool OK()
{
    int sum = 0;
	for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            sum = r[i]+c[j];
            if (maze[i][j] == '*')
            {
                sum--;
            }
            if (sum == cnt)
            {
                printf("YES\n%d %d\n",i+1,j+1);
                return true;
            }
        }
    }
    return false;
}


int main()
{
    while (~scanf("%d%d",&N,&M))
    {
        cnt = 0;
		memset(maze,0,sizeof(maze));
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        for (int i = 0; i < N; i++)
        {
            getchar();
            for (int j = 0; j < M; j++)
            {
                scanf("%c",&maze[i][j]);
                if (maze[i][j] == '*')
                {
                    r[i]++;
                    c[j]++;
                    cnt++;
                }
            }
        }
        if (!OK())
            printf("NO\n");
    }
    return 0;
}


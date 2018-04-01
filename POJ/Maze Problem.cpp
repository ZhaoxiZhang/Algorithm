#include<iostream>
#include<utility>
#include<queue>
#include<cstdio>
#define MAX_N 105
#define MAX_M 105
using namespace std;
const int INF = 100000000;
typedef pair<int, int>P;
char maze[MAX_N][MAX_M+1]; //表示迷宫的字符串数组 
int N,M;

 
int bfs(int sx,int sy,int gx,int gy)
{
	int d[MAX_N][MAX_M]; //到各个位置最短距离的数组 
	int dx[4] = {1,0,-1,0}, dy[4] = { 0,1,0,-1}; //4个方向移动的量 
	queue<P>que;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < M;j++)
		{
			d[i][j] = INF; //所有位置初始化为INF 
		}
	}
	
	que.push(P(sx,sy));
	d[sx][sy] = 0;  //起点压入队列，并把这点距离设置为0 
	
	while (que.size())
	{
		P p = que.front();
		que.pop();
		
		if (p.first == gx && p.second == gy)
		{
			break; //取出的状态为终点，结束搜索 
		}
		
		for (int i = 0; i < 4;i++) //四个方向循环 
		{
			int nx = p.first + dx[i],ny = p.second + dy[i];
			
			if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF)
			{
				que.push(P(nx,ny));  //可以移动则加入队列，并更新该位置距离 
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	return d[gx][gy];
}


int main()
{
	int i,j,res;
	int sx,sy;  //起点坐标
    int gx,gy;  //终点坐标
	scanf("%d%d",&N,&M);
	for (i=0;i<N;i++)
	{
		scanf("%s",maze[i]); 
	}
	for (i=0;i<N;i++)
	{
		for (j=0;j < M;j++)
		{
			if (maze[i][j] == 'S') 
			{
				sx = i;
				sy = j;
			}
			if (maze[i][j] == 'G')
			{
				gx = i;
				gy = j;
			}
		} 
	}
	res = bfs(sx,sy,gx,gy);
	printf("%d\n",res);
	return 0;
} 

#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn =  35;
char maze[maxn][maxn][maxn];
int dis[maxn][maxn][maxn];
int L, R, C;

struct Node
{
    int z, x, y;
    Node(int zz, int xx, int yy): z(zz), x(xx), y(yy) {}
};

int bfs(int sz, int sx, int sy, int gz, int gx, int gy)
{
    queue<Node>que;
    int dx[5] = { -1, 0, 1}, dy[5] = {0, -1, 0, 1}, dz[3] = {0, -1, 1};
    memset(dis, INF, sizeof(dis));

    dis[sz][sx][sy] = 0;
    que.push(Node(sz, sx, sy));

    while (!que.empty())
    {
        Node pos = que.front();
        que.pop();

        if (pos.z == gz && pos.x == gx && pos.y == gy)
        {
            break;
        }

        for (int i = 0; i < 3; i++)
        {
            if (i)
            {
                int nz = pos.z + dz[i], nx = pos.x, ny = pos.y;
                if (nz >= 0 && nz < L && nx >= 0 && nx < R && ny >= 0 && ny < C && maze[nz][nx][ny] != '#' && dis[nz][nx][ny] == INF)
                {
                    que.push(Node(nz, nx, ny));
                    dis[nz][nx][ny] = dis[pos.z][pos.x][pos.y] + 1;
                }
            }
            else
            {
                for (int j = 0; j < 5; j++)
                {
                    int nz = pos.z + dz[i], nx = pos.x + dx[j], ny = pos.y + dy[j];
                    if (nz >= 0 && nz < L && nx >= 0 && nx < R && ny >= 0 && ny < C && maze[nz][nx][ny] != '#' && dis[nz][nx][ny] == INF)
                    {
                        que.push(Node(nz, nx, ny));
                        dis[nz][nx][ny] = dis[pos.z][pos.x][pos.y] + 1;
                    }
                }
            }


        }
    }
    return dis[gz][gx][gy];
}


int main()
{
    //freopen("input.txt", "r", stdin);
    while (~scanf("%d%d%d", &L, &R, &C) && L && R && C)
    {
        int sz, sx, sy, gz, gx, gy;
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                scanf("%s", maze[i][j]);
                for (int k = 0; k < C; k++)
                {
                    if (maze[i][j][k] == 'S')
                    {
                        sz = i, sx = j, sy = k;
                    }
                    if (maze[i][j][k] == 'E')
                    {
                        gz = i, gx = j, gy = k;
                    }
                }
            }
            getchar();
        }
        bfs(sz, sx, sy, gz, gx, gy) == INF ? printf("Trapped!\n") : printf("Escaped in %d minute(s).\n", dis[gz][gx][gy]);
    }
    return 0;
}

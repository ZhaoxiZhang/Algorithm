#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
char maze[maxn][maxn];
bool vis[maxn][maxn];
int n, m, k;
int dx[4] = {0, -1, 0, 1};
int dy[4] = { -1, 0, 1, 0};


void dfs(int mx, int my)
{
    vis[mx][my] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = mx + dx[i], ny = my + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] == '.' && !vis[nx][ny])
        {
            dfs(nx, ny);
        }
    }
    if (k > 0)	maze[mx][my] = 'X',k--;
}

int main()
{
    memset(vis, 0, sizeof(maze));
    bool flag = false;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)   scanf("%s", maze[i]);
    for (int i = 0; i < n && !flag; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == '.')
            {
                dfs(i,j);
                flag = true;
                break;
            }

        }
    }
    for (int i = 0;i < n;i++)	printf("%s\n",maze[i]);
    return 0;
}

/*
 * Description: 假设一个探险家被困在了地底的迷宫之中，要从当前位置开始找到一条通往迷宫出口的路径。
 * 迷宫可以用一个二维矩阵组成，有的部分是墙，有的部分是路。迷宫之中有的路上还有门，
 * 每扇门都在迷宫的某个地方有与之匹配的钥匙，只有先拿到钥匙才能打开门。请设计一个算法，
 * 帮助探险家找到脱困的最短路径。如前所述，迷宫是通过一个二维矩阵表示的，
 * 每个元素的值的含义如下 0-墙，1-路，2-探险家的起始位置，3-迷宫的出口，大写字母-门，小写字母-对应大写字母所代表的门的钥匙
 * Input: 迷宫的地图，用二维矩阵表示。第一行是表示矩阵的行数和列数M和N后面的M行是矩阵的数据，
 * 每一行对应与矩阵的一行（中间没有空格）。M和N都不超过100, 门不超过10扇。
 * Output: 路径的长度，是一个整数
 * SampleInput:
 * 5 5
 * 02111
 * 01a0A
 * 01003
 * 01001
 * 01111
 * SampleOutput:
 * 7
 */

#include <bits/stdc++.h>
using namespace std;
#define SHIFT 5
#define MASK 0x1F
const int maxn = 105;
char maze[maxn][maxn];
int vis[maxn][maxn][35];

typedef struct Node{
    int x, y, step, status;
    Node(int intX, int intY, int intStatus, int intStep){
        x = intX;
        y = intY;
        step = intStep;
        status = intStatus;
    }

    Node(){}
}Node;

bool isLower(char c){
    return c >= 'a' && c <= 'z';
}

bool isUpper(char c){
    return c >= 'A' && c <= 'Z';
}

bool bit_test(int nx, int ny, int status){
    return vis[nx][ny][status >> SHIFT] & (1 << (status & MASK));
}

void bit_set(int nx, int ny, int status){
    vis[nx][ny][status >> SHIFT] |= (1 << (status & MASK));
}

int bfs(int m, int n, Node start){
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    queue<Node>que;
    que.push(start);

    while (!que.empty()){
        Node top = que.front();
        que.pop();

        if (maze[top.x][top.y] == '3')  return top.step;

        for (int i = 0; i < 4; i++){
            int nx = top.x + dx[i], ny = top.y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || maze[nx][ny] == '0')    continue;
            int status = top.status;
            if (isUpper(maze[nx][ny]) && ((status & (1 << (maze[nx][ny] - 'A'))) == 0))  continue;
            if (isLower(maze[nx][ny])){
                status |= (1 << (maze[nx][ny] - 'a'));
            }

            if (!bit_test(nx, ny, status)){
                bit_set(nx, ny, status);
                que.push(Node(nx, ny, status, top.step + 1));
            }
        }
    }
    return 0;
}

int main(){
    int m, n;
    Node start;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++){
        scanf("%s", maze[i]);
        for (int j = 0; j < n; j++){
            if (maze[i][j] == '2'){
                start.x = i;
                start.y = j;
                start.step = 0;
                start.status = 0;
            }
        }
    }
    printf("%d\n", bfs(m, n, start));
    return 0;
}

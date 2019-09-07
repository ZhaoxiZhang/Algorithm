static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int size = grid.size();
        int dis[size + 5][size + 5];
        bool vis[size + 5][size + 5];
        memset(vis, false, sizeof(vis));
        memset(dis, 0x3f3f3f3f, sizeof(dis));

        int dx[] = {-1, -1, -1, 0,  0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        queue<pair<int,int>>que;
        if (grid[0][0] == 0){
            que.push(make_pair(0, 0));
            dis[0][0] = 1;
            vis[0][0] = true;
        }

        while(!que.empty()){
            pair<int, int>p = que.front();
            que.pop();

            if (p.first == size - 1 && p.second == size - 1){
                break;
            }

            for (int i = 0; i < 8; i++){
                int nx = p.first + dx[i], ny = p.second + dy[i];
                if (nx >= 0 && nx < size && ny >= 0 && ny < size && grid[nx][ny] == 0){
                    if (dis[nx][ny] >= dis[p.first][p.second] + 1 && !vis[nx][ny]){
                        dis[nx][ny] = dis[p.first][p.second] + 1;
                        que.push(make_pair(nx, ny));
                        vis[nx][ny] = true;
                    }
                }
            }
        }

        return dis[size - 1][size - 1] == 0x3f3f3f3f ? -1 : dis[size - 1][size - 1];
    }
};
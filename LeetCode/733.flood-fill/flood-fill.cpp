class Solution {
public:
    void bfs(vector<vector<int>>& image, int x, int y, int newColor){
        int m = image.size(), n = image[0].size();
        int val = image[x][y];
        queue<pair<int,int>>que;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        que.push(pair<int,int>(x, y));
        image[x][y] = newColor;
        while (!que.empty()){
            pair<int,int> p = que.front();
            que.pop();
            for (int i = 0; i < 4; i++){
                int sx = p.first + dx[i], sy = p.second + dy[i];
                if (sx >= 0 && sx < m && sy >= 0 && sy < n && image[sx][sy] == val && image[sx][sy] != newColor){
                    que.push(pair<int,int>(sx, sy));
                    image[sx][sy] = newColor;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        bfs(image, sr, sc, newColor);
        return image;
    }
};
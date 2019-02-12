class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0)  return;
        queue<pair<int,int>>que;
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') que.push(pair<int,int>(0, i)), board[0][i] = 'A';
            if (board[m - 1][i] == 'O') que.push(pair<int,int>(m - 1, i)), board[m - 1][i] = 'A';
        }
        for (int i = 1; i < m - 1; i++){
            if (board[i][0] == 'O') que.push(pair<int,int>(i, 0)), board[i][0] = 'A';
            if (board[i][n - 1] == 'O') que.push(pair<int,int>(i, n - 1)),   board[i][n - 1] = 'A';
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        while (!que.empty()){
            pair<int,int>p = que.front();
            que.pop();

            for (int i = 0; i < 4; i++){
                int x = p.first + dx[i], y = p.second + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O'){
                    board[x][y] = 'A';
                    que.push(pair<int,int>(x, y));
                }
            }
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'A')    board[i][j] = 'O';
            }
        }

    }
};
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int vis[n][n];
        int res[n][n];
        memset(vis,0,sizeof(vis));
        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};
        int r = 0,c = 0,di = 0;
        for (int i = 0;i < n * n;i++){
        	res[r][c] = i + 1;
        	vis[r][c] = true;
        	int cr = r + dr[di];
        	int cc = c + dc[di];
        	if (0 <= cr && cr < n && 0 <= cc && cc < n && !vis[cr][cc]){
        		r = cr;
        		c = cc;
        	}else{
        		di = (di + 1) % 4;
        		r += dr[di];
        		c += dc[di];
        	}
        }
        vector<vector<int>>itv;
        for (int i = 0; i < n;i++){
        	vector<int>tmp;
        	for (int j = 0;j < n;j++){
        		tmp.push_back(res[i][j]);
        	}
        	itv.push_back(tmp);
        }
        return itv;
    }
};
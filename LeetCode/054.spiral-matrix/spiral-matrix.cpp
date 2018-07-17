class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
    	int m = matrix.size();
    	if (m == 0)	return res;
    	int n = matrix[0].size();
    	int dr[4] = {0,1,0,-1};
    	int dc[4] = {1,0,-1,0};
    	bool vis[m + 5][n + 5];
        memset(vis,false,sizeof(vis));
    	int r = 0,c = 0,di = 0;
    	for (int i = 0;i < m * n;i++){
    		res.push_back(matrix[r][c]);
    		vis[r][c] = true;
    		int cr = r + dr[di];
    		int cc = c + dc[di];
    		if (0 <= cr && cr < m && 0 <= cc && cc < n && !vis[cr][cc]){
    			vis[cr][cc] = true;
    			r = cr;
    			c = cc;
    		}else{
    			di = (di + 1) % 4;
    			r += dr[di];
    			c += dc[di];
    		}
    	}
    	return res;
    }
};
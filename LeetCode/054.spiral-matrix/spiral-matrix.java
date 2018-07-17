class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length;
        int n = m != 0 ? matrix[0].length : 0;
        List res = new ArrayList(m * n);
        boolean[][] vis = new boolean[m][n];
        int[] dr = {0,1,0,-1};
        int[] dc = {1,0,-1,0};
        int r = 0,c = 0,di = 0;
        for (int i = 0;i < m * n;i++){
            res.add(matrix[r][c]);
            vis[r][c] = true;
            int cr = r + dr[di];
            int cc = c + dc[di];
            
            if (0 <= cr && cr < m && 0 <= cc && cc < n && !vis[cr][cc]){
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
}
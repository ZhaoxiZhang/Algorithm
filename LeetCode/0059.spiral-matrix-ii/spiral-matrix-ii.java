class Solution {
    public int[][] generateMatrix(int n) {
        boolean[][] vis = new boolean[n][n];
        int[][] res = new int[n][n];
        int[] dr = {0,1,0,-1};
        int[] dc = {1,0,-1,0};
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
                r = r + dr[di];
                c = c + dc[di];
            }
        }
        return res;
    }
}
class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int res = 0;
        for (int i = 0;i < m - 2;i++){
            for (int j = 0;j < n - 2;j++){
                if (check(grid,i,j)){
                    res++;
                }
            }
        }
        return res;
    }

    public boolean check(int[][] grid,int row,int col){
        int m = grid.length;
        int n = grid[0].length;
        boolean[] vis = new boolean[10];
        Arrays.fill(vis,false);
        //check unique
        int cnt = 0;
        for (int i = 0;i < 3;i++){
            int sum1 = 0;
            int sum2 = 0;
            for (int j = 0;j < 3;j++){
                if (grid[row + i][col + j] < 1 || grid[row + i][col + j] > 9)   return false;
                if (!vis[grid[row + i][col + j]]){
                    cnt++;
                    vis[grid[row + i][col + j]] = true;
                }
                //check row
                sum1 += grid[row + i][col + j];
                //check col
                sum2 += grid[row + j][col + i];
            }
            if (sum1 != 15) return false;
            if (sum2 != 15) return false;
        }

        if (cnt != 9)   return false;


        //check diagonal
        int x = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int y = grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];

        return x == y;
    }
}
class Solution {
    public int[][] flipAndInvertImage(int[][] A){
        int m = A.length;
        int n = A[0].length;
        for (int i = 0;i < m;i++){
            for (int j = 0;j < n / 2;j++){
                if (A[i][j] == A[i][n - 1 - j]){
                    A[i][j] = A[i][n - 1 - j] = A[i][j] == 1 ? 0 : 1;
                }
            }
        }
        if ((n & 1) == 1){
            for (int i = 0;i < m;i++){
                A[i][n / 2] = A[i][n / 2] == 1 ? 0 : 1; 
            }
        }
        return A;
    }
}
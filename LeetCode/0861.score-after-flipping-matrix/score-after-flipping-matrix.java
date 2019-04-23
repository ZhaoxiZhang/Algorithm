class Solution {
    public int matrixScore(int[][] A) {
        if (A.length == 0 || A[0].length == 0)  return 0;
        int m = A.length, n = A[0].length;
        int res = 0;
        for (int i = 0; i < m; i++){
            if (A[i][0] == 0){
                for (int j = 0; j < n; j++){
                    if (A[i][j] == 0)   A[i][j] = 1;
                    else A[i][j] = 0;
                }
            }
            res += 1 << (n - 1);
        }
        for (int i = 1; i < n; i++){
            int zero = 0, one = 0;
            for (int j = 0; j < m; j++){
                if (A[j][i] == 0)   zero++;
                else one++;
            }
            int maxVal = Math.max(zero, one);
            res += maxVal * (1 << (n - i - 1));
        }
        return res;
    }
}
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if (A.size() == 0 || A[0].size() == 0)  return 0;
        int m = A.size(), n = A[0].size();
        int res = 0;
        int baseVal = 1 << (n - 1);
        for (int i = 0; i < m; i++){
            if (A[i][0] == 0){
                for (int j = 0; j < n; j++){
                    if (A[i][j] == 0)   A[i][j] = 1;
                    else    A[i][j] = 0;
                }
            }
            res += baseVal;
        }

        for (int i = 1; i < n; i++){
            int zero = 0, one = 0;
            for (int j = 0; j < m; j++){
                if (A[j][i] == 0)   zero++;
                else one++;
            }
            int maxVal = max(zero, one);
            res += maxVal * (1 << (n - i - 1));
        }

        return res;
    }
};
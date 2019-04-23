class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        vector<int>sum;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                sum.push_back(A[i] + B[j]);
            }
        }
        int res = 0;
        sort(sum.begin(),sum.end());
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < D.size(); j++) {
                int tmp = -C[i] - D[j];
                res += upper_bound(sum.begin(), sum.end(), tmp) - lower_bound(sum.begin(), sum.end(), tmp);
            }
        }
        return res;
    }
};
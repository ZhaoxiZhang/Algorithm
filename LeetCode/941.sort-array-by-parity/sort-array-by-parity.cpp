class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int>res;
        for (int i = 0; i < A.size(); i++){
            if (!(A[i] & 1)){
                res.push_back(A[i]);
            }
        }
        for (int i = 0; i < A.size(); i++){
            if (A[i] & 1){
                res.push_back(A[i]);
            }
        }
        return res;
    }
};
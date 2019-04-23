class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>tmp;
        int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        solver(res, num, tmp, k, n, 0, 0);
        return res;
    }

    void solver(vector<vector<int>>& res, int num[], vector<int>tmp, int k, int target, int stIndex, int cnt){
        if (cnt == k){
            if (target == 0)    res.push_back(tmp);
        }else{
            for (int i = stIndex; i < 9; i++){
                if (target - num[i] < 0)    break;
                tmp.push_back(num[i]);
                solver(res, num, tmp, k, target - num[i], i + 1, cnt + 1);
                tmp.pop_back();
            }
        }
    }
};
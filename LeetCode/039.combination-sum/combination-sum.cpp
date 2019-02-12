class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>tmp;
        solver(res, candidates, tmp, target, 0);
        return res;
    }

    void solver(vector<vector<int>>& res, vector<int>& candidates, vector<int>tmp, int target, int stIndex){
        if (target < 0) return;
        if (target == 0)    res.push_back(tmp);
        for (int i = stIndex; i < candidates.size(); i++){
            tmp.push_back(candidates[i]);
            solver(res, candidates, tmp, target - candidates[i], i);
            tmp.pop_back();
        }
    }
};
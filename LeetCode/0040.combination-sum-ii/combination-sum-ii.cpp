class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>tmp;
        sort(candidates.begin(), candidates.end());
        solver(res, candidates, tmp, target, 0);
        return res;
    }

    void solver(vector<vector<int>>& res, vector<int>& candidates, vector<int>tmp, int target, int stIndex){
        if (target < 0) return;
        else if (target == 0)    res.push_back(tmp);
        else
            for (int i = stIndex; i < candidates.size(); i++){
                if (i > stIndex && candidates[i] == candidates[i - 1])    continue;
                tmp.push_back(candidates[i]);
                if (target - candidates[i] < 0) break;
                solver(res, candidates, tmp, target - candidates[i], i + 1);
                tmp.pop_back();
            }
    }
};
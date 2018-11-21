class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        if (n < 4)   return false;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        int tot =  0;
        for (auto v : nums) tot += v;
        if (tot % 4) return false;
        
        tot /= 4;
        if (nums[0] > tot) return false;
        
        vis.assign(n, false);
        for (int i = 0; i < 4; i++) {
            if (!dfs(nums, 0, tot)) return false;
        }
        return true;
    }
    
    bool dfs(vector<int>& nums, int start, int target) {
        if (target == 0) return true;
        
        for (int i = start; i < nums.size(); i++) {
            if (vis[i] || nums[i] > target) continue;
            vis[i] = true;
            if (dfs(nums, i+1, target-nums[i])) return true;
            vis[i] = false;
        }
        return false;
    }
    
    
private:
    vector<bool> vis;
};

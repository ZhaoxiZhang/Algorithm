class Solution {
public:    
    int findMaximumXOR(vector<int>& nums) {
        return helper(nums, nums.begin(), nums.end(), nums.begin(), nums.end(), 0, 1 << 30);
    }

    typedef vector<int>::iterator Iter;
    int helper(vector<int>& nums, Iter lstart, Iter lend, Iter rstart, Iter rend, int val, int mask) {
        if(lstart == lend || rstart == rend || mask == 0) return val;
        auto cond = [mask](int num){return num & mask;};
        auto lmid = partition(lstart, lend, cond), rmid = partition(rstart, rend, cond);
        if(lmid == lend && rmid == rend || lmid == lstart && rmid == rstart)
            return helper(nums, lstart, lend, rstart, rend, val, mask >> 1);
        else return max(
            helper(nums, lstart, lmid, rmid, rend, val | mask, mask >> 1),
            rstart < lend ? 0 : helper(nums, lmid, lend, rstart, rmid, val | mask, mask >> 1));
    }
};
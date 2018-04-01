class Solution {
public:
    //59ms
    int totalHammingDistance(vector<int>& nums) {
        int res = 0,len = nums.size();
        for (int i = 0;i < 32;i++){
            int cnt = 0;
            for (int j = 0;j < len;j++){
                cnt += (nums[j] >> j) & 1;
            }
            res += (len - cnt) * cnt;
        }
        return res;
    }
};
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int st = 0,ed = 0,sum = 0,res = len + 1;
        for (;;){
            while (ed < len && sum < s){
                sum += nums[ed++];
            }
            if (sum < s)	break;
            res = min(res,ed - st);
           sum -= nums[st++];
        }
        if (res == len + 1)	return 0;
        else	return res;
    }
};
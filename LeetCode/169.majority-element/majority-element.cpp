class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0,cnt = 0;
        for (int i = 0;i < nums.size();i++){
            if (cnt == 0){
                majority = nums[i];
                cnt++;
            }else if (majority == nums[i]){
                cnt++;
            }else{
                cnt--;
            }
        }
        return majority;
    }
};
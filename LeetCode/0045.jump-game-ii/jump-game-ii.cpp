class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1)   return 0;
        int index = 0;
        int res = 0;
        while (index < size){
            int step = nums[index];
            int maxStep = 0;
            int pos = index;
            if (index + step >= size - 1){
            	res++;
            	break;
            }
            for (int j = 1; j <= step; j++){
            	if (j + nums[index + j] > maxStep){
                    maxStep = j + nums[index + j];
                    pos = index + j;
                }
            }
            res++;
            index = pos;
            if (index == size - 1)	break;
        }
        return res;
    }
};
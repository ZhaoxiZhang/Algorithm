class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        for (int i = 0;i < n;){
            if (i + nums[i] >= n - 1)   return true;
            int m = nums[i];
            int maxx = 0;
            int pos = i;
            for (int j = 1;j <= m;j++){
                int len = i + j + nums[i + j];
                if (len > maxx){
                    pos = i + j;
                    maxx = len;
                }
            }
            //System.out.println(pos);
            //没有前进
            if (pos == i)   return false;
            i = pos;
        }
        return false;
    }
}
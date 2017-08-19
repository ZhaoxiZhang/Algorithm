class Solution {
public:
    //9ms
    int singleNumber(vector<int>& nums) {
        int ones = 0,twos = 0;
        for (unsigned int i = 0;i < nums.size();i++){
            //ones&~twos以及twos&~ones都是为了清零操作，两者二进制位都为1时清零
            ones = (ones ^ nums[i]) & (~twos);
            twos = (twos ^ nums[i]) & (~ones);
        }
        return ones;
    }
};


class Solution {
public:
    //9ms
    int singleNumber(vector<int>& nums) {
        int ones = 0,twos = 0,threes = 0;
        for (unsigned int i = 0;i < nums.size();i++){
            //以下两句代码不能颠倒次序，如若颠倒，则一个数先记录于ones，
            //然后twos的值依赖于ones及这个数，那么这个数就被统计了两次
            twos |= (nums[i] & ones);  //记录有哪些为进制位为1且出现两次存于twos
            ones ^= nums[i];           //记录有哪些二进制位为1且出现一次存于ones

            //以下三句是清零操作
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};

class Solution {
public:
    //12ms
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0;i < 32;i++){
            int cnt = 0;
            int mask = 1 << i;
            for (int j = 0;j < nums.size();j++){
                if (nums[j] & mask){
                    cnt++;
                }
            }
            if (cnt % 3){
                res |= mask;
            }
        }
        return res;
    }
};
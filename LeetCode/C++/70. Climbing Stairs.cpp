class Solution {
public:
    //3ms
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int a = 1,b = 2,res;
        for (int i = 2; i < n;i++){
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};

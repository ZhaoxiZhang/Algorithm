class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long cap = n - 1;
        cap |= cap >> 1;
        cap |= cap >> 2;
        cap |= cap >> 4;
        cap |= cap >> 8;
        cap |= cap >> 16;
        cap = cap + 1;
        cap >>= 1;
        
        if (m < cap && cap < n || (m == cap && !(n & (n - 1))))   return 0;
        else if (m == cap && (n & (n - 1)) != 0)    return m;
        else{
            int res = m;
            for (long i = m + 1L; i <= n; i++){
                res &= i;
            }
            return res;
        }
    }
};
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)   return INT_MAX;
        bool isNegative = false;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) isNegative = true;
        long long dividendL = dividend < 0 ? -(long long)dividend : (long long)dividend;
        long long divisorL = divisor < 0 ? -(long long)divisor : (long long)divisor;
        if (dividendL < divisorL) return 0;
        int res = 0;
        while (dividendL >= divisorL){
            int cnt = 1;
            long long tmp = divisorL;
            while (dividendL >= (tmp << 1)){
                tmp <<= 1;
                cnt <<= 1;
            }

            res += cnt;
            dividendL -= tmp;
        }

        if (isNegative) return -res;
        return res;
    }
};
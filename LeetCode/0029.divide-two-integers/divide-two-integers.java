class Solution {
    public int divide(int dividend, int divisor) {
        boolean isNegative = false;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) isNegative = true;
        long dividendL = dividend > 0 ? dividend : -(long)dividend;
        long divisorL = divisor > 0 ? divisor : -(long)divisor;
        if (dividendL == 0 || dividendL < divisorL)   return 0;
        long res = 0;
        while (dividendL >= divisorL){
            long cnt = 1;
            long tmp = divisorL;
            while (dividendL >= (tmp << 1)){
                cnt <<= 1;
                tmp <<= 1;
            }

            res += cnt;
            dividendL -= tmp;
        }
        if (isNegative == true) res = -res;
        if (res > Integer.MAX_VALUE || res < Integer.MIN_VALUE) res = Integer.MAX_VALUE;
        return (int)res;
    }
}
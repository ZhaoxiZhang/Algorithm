class Solution {
    public double myPow(double x, int n) {
        long ln = n;
        boolean isNegative = false;
        if (n < 0) {
            ln = -ln;
            isNegative = true;
        }
        double res = 1;
        while (ln != 0){
            if ((ln & 1) != 0){
                res *= x;
            }
            x *= x;
            ln >>= 1;
        }
        if (isNegative){
            res = 1 / res;
        }
        return res;
    }
}
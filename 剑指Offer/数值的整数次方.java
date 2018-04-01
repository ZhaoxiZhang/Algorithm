public class Solution {
    public double Power(double base, int exponent) {
        boolean flag = false;
        if (exponent < 0){
            exponent = -exponent;
            flag = true;
        }
        double res = 1;
        while (exponent > 0){
            if ((exponent & 1) != 0){
                res *= base;
            }
            base *= base;
            exponent >>= 1;
        }
        if (flag){
            res = 1 / res;
        }
        return res;
    }
}

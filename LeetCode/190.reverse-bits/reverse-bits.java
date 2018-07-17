public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        long flag = Integer.MAX_VALUE + 1L;
        int res = 0,x = 1;
        while (flag != 0){
            if ((n & flag) != 0){
                res += x;
            }
            x <<= 1;;
            flag >>= 1;
        }
        return res;
    }
}
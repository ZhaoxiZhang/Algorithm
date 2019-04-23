class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 10, val = 9;
        for (int i = 1; i < n; i++){
            val *= (10 - i);
            res += val;
        }
        return res;
    }
}
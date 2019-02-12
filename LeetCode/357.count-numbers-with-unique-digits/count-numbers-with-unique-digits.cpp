class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 10, base = 9;
        for (int i = 1; i < n; i++){
            base *= (10 - i);
            res += base;
        }
        return res;
    }
};
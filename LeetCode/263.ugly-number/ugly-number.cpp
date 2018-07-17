class Solution {
public:
    bool isUgly(int num) {
        if (num == 1)   return true;
        if (num <= 0)    return false;
        return ((num % 2 == 0) && isUgly(num / 2)) || ((num % 3 == 0) && isUgly(num / 3)) || ((num % 5 == 0) && isUgly(num / 5));
    }
};
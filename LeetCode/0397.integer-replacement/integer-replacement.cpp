class Solution {
public:
    int integerReplacement(int n) {
        return solve((long)n);
    }

    int solve(long n){
        if (n == 1) return 0;
        else if (!(n & 1))  return 1 + solve(n >> 1);
        else    return 1 + min(solve(n - 1), solve(n + 1));
    }
};
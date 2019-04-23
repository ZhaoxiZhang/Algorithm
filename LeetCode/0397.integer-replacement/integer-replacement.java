class Solution {
    public int integerReplacement(int n) {
        return solve((long)n);
    }


    public int solve(long n){
        if (n == 1) return 0;
        else if ((n & 1) == 0)  return 1 + solve(n >> 1);
        else return 1 + Math.min(solve(n - 1), solve(n + 1));
    }
}
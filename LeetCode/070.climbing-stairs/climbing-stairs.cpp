class Solution {
private:
    int FibHelper(int n, vector<int>&res){
        if (n < 3)  return n;
        else if (res[n] == 0){
            res[n] = FibHelper(n - 1, res) + FibHelper(n - 2, res);
        }
        return res[n];
    }
public:
    int climbStairs(int n){
        vector<int>res;
        res.resize(n + 1);
        return FibHelper(n, res);
    }
};

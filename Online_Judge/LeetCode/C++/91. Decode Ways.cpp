#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (!len)   return 0;
        vector<int>dp(len + 1,0);
        if (dp[0] == '0'){
            dp[0] = 0;
            dp[1] = 1;
        } else {
            dp[0] = 1;
            if (10*(dp[0] - '0') + (dp[1] - '0') <= 26 && dp[1] != '0') dp[1] = 2;
            else    dp[1] = 1;
        }
        for (int i = 2;i < len;i++){
            dp[i] = dp[i - 1];
            if (dp[i - 1] != '0' && 10*(dp[i - 1] - '0') + (dp[i] - '0') <= 26) dp[i] += dp[i - 2];
        }
        return dp[len - 1];
    }
};

int main(){
    string s;
    Solution solution;
    cin >> s;
    cout << solution.numDecodings(s) << endl;
    return 0;
}

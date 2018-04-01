#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (!len)   return 0;
        vector<int>dp(len + 1,0);
        if (s[0] == '0'){
            return 0;
        } else {
            dp[0] = 1;
            if (10*(s[0] - '0') + (s[1] - '0') <= 26){
                if (s[1] == '0')   dp[1] = 1;
                else    dp[1] = 2;
            }
            else    dp[1] = 1;
        }
        for (int i = 2;i < len;i++){
            if (s[i] == '0'){
                if (s[i - 1] != '0'){
                    dp[i] == dp[i - 2];
                }else{
                    if (s[i - 2] != '0'){
                        dp[i] = dp[i - 3];
                    }else{
                        return 0;
                    }
                }
            }else{
                if (s[i - 1] != '0' && 10 * (s[i - 1] - '0') + (s[i] - '0') <= 26){
                    dp[i] = max(dp[i - 1],dp[i - 2] + 2);
                }else{
                    dp[i] = dp[i - 1];
                }
            }
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

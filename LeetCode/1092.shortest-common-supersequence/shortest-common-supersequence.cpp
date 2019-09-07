class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string res = "";
        int len1 = str1.size(), len2 = str2.size();
        int dp[len1 + 5][len2 + 5];
        memset(dp, 0, sizeof(dp));
        int i, j;
        for (i = 1; i <= len1; i++){
            for (j = 1; j <= len2; j++){
                if (str1[i - 1] == str2[j - 1])    dp[i][j] = dp[i - 1][j - 1] + 1;
                else    dp[i][j] = dp[i][j - 1] > dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j];
            }
        }
        i = len1, j = len2;
        string common = "";
        while (dp[i][j]){
            if (dp[i][j] == dp[i - 1][j])   i--;
            else if (dp[i][j] == dp[i][j - 1])  j--;
            else    common += str1[i - 1], i--, j--;
        }
        
        reverse(common.begin(), common.end());
        
        int len3 = common.size();
        i = 0, j = 0;
        for (int k = 0; k < len3; k++){
            while (i < len1 && str1[i] != common[k]){
                res += str1[i++];
            }
            while (j < len2 && str2[j] != common[k]){
                res += str2[j++];
            }
            res += common[k];
            i++;
            j++;
        }
        while (i < len1){
            res += str1[i++];
        }
        while (j < len2){
            res += str2[j++];
        }
        return res;
    }
};
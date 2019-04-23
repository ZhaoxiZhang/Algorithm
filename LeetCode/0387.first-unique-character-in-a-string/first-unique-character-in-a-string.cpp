class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        for (int i = 0;i < s.size();i++){
            cnt[s[i] - 'a']++;
        }
        for (int i = 0;i < s.size();i++){
            if (cnt[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};
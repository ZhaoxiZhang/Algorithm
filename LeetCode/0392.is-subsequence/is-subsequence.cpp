class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.size(), tlen = t.size();
        int index = 0;
        for (int i = 0; i < tlen; i++){
            if (t[i] == s[index]){
                index++;
                if (index == slen)  break;
            }
        }
        return index == slen ? true : false;
    }
};
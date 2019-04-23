class Solution {
public:
    char findTheDifference(string s, string t) {
        int a =0,b = 0;
        char ch; 
        for (unsigned int i = 0;i < s.size();i++){
            a ^= (1 << (s[i] - 'a'));
        }
        for (unsigned int i = 0;i < t.size();i++){
            b ^= (1 << (t[i] - 'a'));
        }
        for (int i = 0;i < 26;i++){
            if ((a & 1) != (b & 1)){
                ch = 'a' + i;
                break;
            }
            a >>= 1;
            b >>= 1;
        }
        return ch;
    }
};
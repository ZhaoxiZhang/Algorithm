class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "")   return 0;
        int nxt[needle.size() + 5];
        int k = -1, i = 0;
        nxt[0] = -1;
        while (i < needle.size()){
            if (k == -1 || needle[k] == needle[i]){
                k++;
                i++;
                if (needle[k] != needle[i]) nxt[i] = k;
                else    nxt[i] = nxt[k];
            }else{
                k = nxt[k];
            }
        }

        k = 0, i = 0;
        while (i < haystack.size()){
            if (k == -1 || needle[k] == haystack[i]){
                k++;
                i++;
            }else{
                k = nxt[k];
            }
            if (k == needle.size()) break;
        }

        if (k == needle.size()) return i - k;
        else    return -1;
    }
};
class Solution {
    public int strStr(String haystack, String needle) {
        if (haystack == null || needle == null) return -1;
        if (needle.equals(""))  return 0;

        char[] origin = haystack.toCharArray();
        char[] pattern = needle.toCharArray();

        int[] nxt = new int[pattern.length + 5];

        int k = -1, i = 0;
        nxt[0] = -1;
        while (i < pattern.length){
            if (k == -1 || pattern[k] == pattern[i]){
                k++;
                i++;
                if (i < pattern.length && pattern[k] != pattern[i]) nxt[i] = k;
                else    nxt[i] = nxt[k];
            }else    k = nxt[k];
        }

        k = 0;
        i = 0;
        while (i < origin.length){
            if (k == -1 || pattern[k] == origin[i]){
                k++;
                i++;
            }else    k = nxt[k];
            if (k == pattern.length)    break;
        }

        if (k == pattern.length)    return i - k;
        else    return -1;
    }
}
class Solution {
    public boolean isSubsequence(String s, String t) {
        int slen = s.length(), tlen = t.length();
        int index = 0;
        for (int i = 0; i < tlen; i++){
            if (index == slen)  break;
            if (s.charAt(index) == t.charAt(i)){
                index++;
            }
        }
        return index == slen ? true : false;
    }
}
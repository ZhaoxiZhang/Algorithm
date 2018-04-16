class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0)   return new String("");
        if (strs.length == 1)   return strs[0];
        int pos = Math.min(strs[0].length(),strs[1].length());
        for (int i = 1;i < strs.length;i++){
            int j = 0;
            pos = Math.min(pos,strs[i].length());
            while (j < pos && strs[0].charAt(j) == strs[i].charAt(j)){j++;}
            pos = Math.min(pos,j);
        }
        return new String(strs[0].substring(0,pos));
    }
}
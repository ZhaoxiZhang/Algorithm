import java.util.Arrays;

public class Solution {
    //56ms
    public int lengthOfLongestSubstring(String s) {
        int[] pos = new int[256];
        char[] str = s.toCharArray();
        Arrays.fill(pos,-1);
        int st = 0,res = 0;
        int len = s.length();
        for (int i = 0;i < len;i++){
            int index = str[i];
            if (pos[index] == -1 || pos[index] < st){
                pos[index] = i;
                res = Math.max(res,i - st + 1);
            }else {
                st = pos[index] + 1;
                pos[index] = i;
            }
        }
        return res;
    }
}
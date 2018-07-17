public class Solution {
    public String ReverseSentence(String str) {
        char[] cstr = str.toCharArray();
        char[] res = new char[str.length()];
        int j = 0;
        for (int i = cstr.length - 1;i >= 0;i--){
            int cnt = 0;
            while (i >= 0 && cstr[i] != ' '){
                i--;
                cnt++;
            }
            for (int k = i + 1;cnt > 0;k++,j++,cnt--){
                res[j] = cstr[k];
            }
            if (i >= 0)  res[j++] = ' ';
        }
        return new String(res);
    }
}

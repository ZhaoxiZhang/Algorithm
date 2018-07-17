public class Solution {
    public String LeftRotateString(String str,int n) {
        char cstr[] = str.toCharArray();
        int len = cstr.length;
        if (len == 0)   return str;
        n = n % len;
        char tmp;
        for (int i = 0;i < n / 2;i++){
            tmp = cstr[i];
            cstr[i] = cstr[n - 1 - i];
            cstr[n - 1 - i] = tmp;
        }
        for (int i = 0; i < (len - n) / 2;i++){
            tmp = cstr[i + n];
            cstr[i + n] = cstr[len - 1 - i];
            cstr[len - 1 - i] = tmp;
        }
        for (int i = 0;i < len / 2;i++){
            tmp = cstr[i];
            cstr[i] = cstr[len - 1 - i];
            cstr[len - 1 - i] = tmp;
        }
        str = String.valueOf(cstr);
        return str;
    }
}
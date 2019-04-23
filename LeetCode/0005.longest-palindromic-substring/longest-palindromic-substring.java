class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0)   return "";
        char[] schar = s.toCharArray();
        char[] str = new char[2 * schar.length + 5];
        int[] p = new int[2 * schar.length + 5];
        int length = schar.length;
        int pos = 0;
        str[pos++] = '$';
        str[pos++] = '#';
        for (int i = 0; i < length; i++){
            str[pos++] = schar[i];
            str[pos++] = '#';
        }

        length = pos;
        int id = 0, mx = 0;
        for (int i = 0; i < length; i++){
            p[i] = mx > i ? Math.min(p[2 * id - i], mx - i) : 1;
            while (i - p[i] >= 0 && str[i - p[i]] == str[i + p[i]])  p[i]++;
            if (i + p[i] > mx){
                mx = i + p[i];
                id = i;
            }
        }

        int size = 0;
        for (int i = 0; i < length; i++){
            if (p[i] > size){
                size = p[i];
                pos = i;
            }    
        }

        StringBuilder stringBuilder = new StringBuilder();
        for (int i = pos - size + 1; i <= pos; i++){
            if (str[i] == '#' || str[i] == '$') continue;
            stringBuilder.append(str[i]);
        }
        for (int i = pos + 1; i < pos + size; i++){
            if (str[i] == '#' || str[i] == '$') continue;
            stringBuilder.append(str[i]);
        }

        return stringBuilder.toString();
    }
}
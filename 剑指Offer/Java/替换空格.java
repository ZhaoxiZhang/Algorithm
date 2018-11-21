public class Solution {
    public class Solution {
    public String replaceSpace(StringBuffer str) {
        int i = 0,blank = 0;
        while (i < str.length()){
            if (str.charAt(i++) == ' '){
                blank++;
            }
        }
        int originLength = str.length();
        int newLength = originLength + 2 * blank;
        char[] cstr = new char[newLength];
        originLength--;
        newLength--;
        while (originLength >= 0 && originLength <= newLength){
            if (str.charAt(originLength) == ' '){
                cstr[newLength--] = '0';
                cstr[newLength--] = '2';
                cstr[newLength--] = '%';
                originLength--;
            }else{
                cstr[newLength--] = str.charAt(originLength--);
            }
        }
        return new String(cstr);
    }
}
}
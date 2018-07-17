public class Solution {
    public String replaceSpace(StringBuffer str) {
        //System.out.println(str.length());
        for (int i = 0;i < str.length();i++){
            if (str.charAt(i) == ' '){
                str.replace(i,i + 1,"%20");
            }
        }
        return str.toString();
    }
}
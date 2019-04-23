class Solution {
    public String shiftingLetters(String S, int[] shifts) {
        char[] str = new char[S.length()];
        int finalen = shifts[shifts.length - 1];
        for (int i = shifts.length - 2;i >= 0;i--){
            int tmp = shifts[i];
            shifts[i] = (shifts[i] + finalen) % 26;
            finalen = (finalen + tmp) % 26;
        }
        for (int i = 0;i < S.length();i++){
            str[i] = (char)((shifts[i] + S.charAt(i) - 97) % 26 + 97);
        }
        String s = new String(str);
        return  s;
    }
}
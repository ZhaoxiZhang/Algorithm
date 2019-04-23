class Solution {
    public List<String> commonChars(String[] A) {
        int length = A.length;
        int[][] cnt = new int[length][26];
        for (int i = 0; i < length; i++){
            char[] cstr = A[i].toCharArray();
            for (int j = 0; j < cstr.length; j++){
                cnt[i][cstr[j] - 'a']++;
            }
        }
        List<String>res = new ArrayList<>();
        for (int i = 0; i < 26; i++){
            int val = 100 * 100 + 5;
            for (int j = 0; j < length; j++){
                val = Math.min(cnt[j][i], val);
            }
            while (val-- > 0){
                res.add(String.valueOf((char)(i + 'a')));
            }
        }
        return res;
    }
}
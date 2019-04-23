class Solution {
    public int maxProduct(String[] words) {
        int size = words.length;
        int[] val = new int[size + 5];
        int res = 0;
        for (int i = 0; i < size; i++){
            char[] cstr = words[i].toCharArray();
            int length = cstr.length;
            for (int j = 0; j < length; j++){
                val[i] |= (1 << (cstr[j] - 'a'));
            }

            for (int j = 0; j < i; j++){
                if ((val[j] & val[i]) == 0){
                    res = Math.max(res, words[i].length() * words[j].length());
                }
            }
        }

        return res;
    }
}
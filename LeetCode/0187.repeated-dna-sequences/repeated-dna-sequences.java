class Solution {
    final int SHIFT = 5;
    final int MASK = 0x1F;
    private void bitSet(int i, int[] a){    a[i >> SHIFT] |= (1 << (i & MASK)); }
    private boolean bitTest(int i, int[] a){    return (a[i >> SHIFT] & (1 << (i & MASK))) != 0; }
    
    public List<String> findRepeatedDnaSequences(String s) {
        char[] cstr = s.toCharArray();
        int[] mp = {0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0};
        int[] once = new int[1024 * 1024 * 2 / 32 + 1];
        HashSet<String>st = new HashSet<>();

        int length = s.length();
        for (int i = 0; i < length - 9; i++){
            int value = 0;
            for (int j = i; j < i + 10; j++){
                value <<= 2;
                value |= (mp[(int)(cstr[j] - 'A')]);
            }
            if (bitTest(value, once)){
                st.add(s.substring(i, i + 10));
            }else{
                bitSet(value, once);
            }

        }

        return new ArrayList<String>(st);
    }
}
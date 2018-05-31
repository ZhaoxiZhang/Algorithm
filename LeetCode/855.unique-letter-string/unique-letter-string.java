class Solution {
    public int uniqueLetterString(String S) {
        List<Integer>[] posList = new List[26];
        double mod = 1e9 + 7;
        int res = 0;
        for (int i = 0;i < 26;i++){
            posList[i] = new ArrayList<>();
        }
        for (int i = 0;i < S.length();i++){
            posList[S.charAt(i) - 'A'].add(i);
        }
        for (int i = 0;i < 26;i++){
            for (int j = 0;j < posList[i].size();j++){
                int first = j == 0 ? - 1 : posList[i].get(j - 1);
                int last = j == posList[i].size() - 1? S.length() : posList[i].get(j + 1);
                res += (posList[i].get(j) - first) * (last - posList[i].get(j));
                res %= mod;
            }
        }
        return res;
    }
}
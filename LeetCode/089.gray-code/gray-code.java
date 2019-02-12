class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer>res = new ArrayList<>();
        res.add(0);
        int bit;
        for (int i = 0; i < n; i++){
            bit = 1 << i;
            int resSize = res.size() - 1;
            while (resSize >= 0){
                res.add(res.get(resSize)^bit);
                resSize--;
            }
        }
        return res;
    }
}
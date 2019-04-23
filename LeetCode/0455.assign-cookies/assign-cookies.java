class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int res = 0;
        int gi = g.length - 1;
        for (int i = s.length - 1; i >= 0 && gi >= 0; i--){
            while (gi >= 0 && g[gi] > s[i])    gi--;
            if (gi >= 0) {
                res++;
                gi--;
            }
        }
        return res;
    }
}
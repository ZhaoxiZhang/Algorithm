class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = g.size() - 1;
        int res = 0;
        for (int si = s.size() - 1; si >= 0 && gi >= 0; si--){
            while (gi >= 0 && g[gi] > s[si])    gi--;
            if (gi >= 0){
                res++;
                gi--;
            }
        }
        return res;
    }
};
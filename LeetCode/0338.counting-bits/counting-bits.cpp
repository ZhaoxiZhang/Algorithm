class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>res = vector<int>(num + 1, 0);
        int cnt = 0;
        for (int i = 1; i <= num; i++){
            res[i] = res[i >> 1] + (i & 1);
        }

        return res;
    }
};
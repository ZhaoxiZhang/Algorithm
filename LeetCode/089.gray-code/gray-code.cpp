class Solution {
public:
    /* µäÐÍ¸ñÀ×Âë
     * 0000
     * 0001
     * 0011 0010
     * 0110 0111 0101 0100
     * 1100 1101 1111 1110 1010 1011 1001 1000
     */
    vector<int> grayCode(int n) {
        vector<int>res;
        res.push_back(0);
        int bit;
        for (int i = 0; i < n; i++){
            bit = 1 << i;
            int resSize = res.size() - 1;
            while (resSize >= 0){
                res.push_back(res[resSize]^bit);
                resSize--;
            }
        }
        return res;
    }
};
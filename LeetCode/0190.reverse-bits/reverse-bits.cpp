class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint64_t flag = INT_MAX + 1L;
        uint32_t res = 0,x = 1;
        while (flag){
            if (flag & n){
                res += x;
            }
            x <<= 1;
            flag >>= 1;

        }
        return res;
    }
};
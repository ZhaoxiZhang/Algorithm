class Solution {
public:
    int findComplement(int num) {
        int res = 0,bit = 1;;
        for (int i = 0;i < 32 && num;i++){
            if (!(num & 1)) res += bit;
            bit <<= 1;
            num >>= 1;
        }
        return res;
    }
};
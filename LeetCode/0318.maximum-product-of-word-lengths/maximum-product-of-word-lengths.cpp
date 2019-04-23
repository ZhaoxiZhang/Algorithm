class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = words.size();
        int val[size + 5] = {0};
        int res = 0;
        for (int i = 0; i < size; i++){
            int length = words[i].size();
            for (int j = 0; j < length; j++){
                val[i] |= (1 << (words[i][j] - 'a'));
            }

            for (int j = 0; j < i; j++){
                if (!(val[i] & val[j])){
                    res = max(res, (int)(words[i].size() * words[j].size()));
                }
            }
        }

        return res;
    }
};
class Solution {
public:
    int minIncrementForUnique(vector<int> &A) {
        int size = A.size();
        if (size == 0)  return 0;
        vector<int>tmp;
        map<int, int>mp;
        sort(A.begin(), A.end());
        int val = A[0];
        for (int i = 1; i < size; i++) {
            mp[A[i]] = 1;
            if (A[i] == val) {
                tmp.push_back(val);
            } else {
                val = A[i];
            }
        }
        size = tmp.size();
        int res = 0;
        if (size == 0) {
            res = 0;
        } else {
            int index = tmp[0];
            for (int i = 0; i < size; i++) {
                index = index < tmp[i] ? tmp[i] : index;
                while (mp[index] == 1 || index < tmp[i])  index++;
                mp[index] = 1;
                res += index - tmp[i];
            }
        }

        return res;
    }
};
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int>res, cur1, cur2;
        for (int i : A){
            cur2 = {i};
            for (int j : cur1)  cur2.insert(i | j);
            cur1 = cur2;
            for (int val : cur1)    res.insert(val);
        }
        return res.size();
    }
};
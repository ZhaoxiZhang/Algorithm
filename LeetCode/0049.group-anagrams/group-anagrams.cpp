class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        unordered_map<string,vector<string>>mp;
        vector<vector<string>> res;
        for (int i = 0; i < size; i++){
            string copy(strs[i]);
            sort(copy.begin(), copy.end());
            mp[copy].push_back(strs[i]);
        }
        for (unordered_map<string, vector<string>>::iterator it = mp.begin(); it != mp.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};
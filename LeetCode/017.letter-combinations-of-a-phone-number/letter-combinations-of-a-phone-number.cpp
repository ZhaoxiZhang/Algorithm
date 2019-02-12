class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string str[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>res;
        string value;
        if (digits.size() == 0) return res;
        helper(res, str, digits, 0, value);
        return res;
    }

    void helper(vector<string>&res, string str[], string digits, int index, string value){
        if (index >= digits.size()){
            res.push_back(value);
            return;
        }
        for (int i = 0; i < str[digits[index] - '2'].size(); i++){
            helper(res, str, digits, index + 1, value + str[digits[index] - '2'][i]);
        }
    }
};
class Solution {
public:
    string reverseString(string s) {
        string res;
    	for (int i = s.size() - 1;i >= 0;i--){
        	res.push_back(s[i]);
        }
    	return res;
    }
};
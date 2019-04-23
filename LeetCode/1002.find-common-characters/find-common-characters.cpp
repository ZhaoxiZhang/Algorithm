class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int size = A.size();
        int cnt[size][26] = {0};
        vector<string>res;
        for (int i = 0; i < size; i++){
            int length = A[i].size();
            for (int j = 0; j < length; j++){
                cnt[i][A[i][j] - 'a']++;
            }
        }
    
        
        for (int i = 0; i < 26; i++){
            int val = 100 * 100 + 5;
            for (int j = 0; j < size; j++){
                val = min(val, cnt[j][i]);
            }
            
            while (val--){
                string tmp;
                tmp += (char)(i + 'a');
                res.push_back(tmp);
            }    
        }
        return res;
    }
};
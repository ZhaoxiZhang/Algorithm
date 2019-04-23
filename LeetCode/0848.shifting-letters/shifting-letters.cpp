class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int finalen = shifts[shifts.size() - 1];
        for (int i = shifts.size() - 2;i >= 0;i--){
        	int tmp = shifts[i];
        	shifts[i] = (shifts[i] + finalen) % 26;
        	finalen = (finalen + tmp) % 26;
        }
        for (int i = 0;i < S.size();i++){
        	S[i] = (shifts[i] + S[i] - 97) % 26 + 97;
        }
        return S;
    }
};
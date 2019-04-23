class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int point = 0;
        int sum = 0;
        int size = tokens.size();
        for (int i = 0; i < size; i++) sum += tokens[i];
        int start = 0, end = size - 1;
        sort(tokens.begin(), tokens.end());
        for (;;){
            if (start > end || P < tokens[start])    break;
            while (start <= end && P >= tokens[start]){
                point++;
                P -= tokens[start];
                start++;
            }
            while (point > 0 && P < tokens[start] && start < end){
                point--;
                P += tokens[end];
                end--;
            }
        }
        return point;
    }
};
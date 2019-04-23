class Solution {
    public int bagOfTokensScore(int[] tokens, int P) {
        if (tokens == null || tokens.length == 0)   return 0;
        Arrays.sort(tokens);
        int length = tokens.length;
        int point = 0;
        int start = 0, end = length - 1;
        for (;;){
            if (start > end || P < tokens[start])   break;
            while (start <= end && P >= tokens[start]){
                point++;
                P -= tokens[start++];
            }
            while (point > 0 && start < end && P < tokens[start]){
                point--;
                P += tokens[end--];
            }
        }
        return point;
    }
}
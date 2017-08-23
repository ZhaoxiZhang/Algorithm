class Solution {
public:
    //6ms
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return 0;
        int res = 0,right = 1,leftval = prices[0];
        int len = prices.size();
        while (right < len){
            if (prices[right] > leftval){
                res = max(res,prices[right] - leftval);
            } else{
                leftval = prices[right];
            }
            right++;
        }
        return res;
    }
};

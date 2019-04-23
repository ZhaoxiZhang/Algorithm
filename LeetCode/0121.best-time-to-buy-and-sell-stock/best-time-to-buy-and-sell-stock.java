class Solution {
    public int maxProfit(int[] prices) {
        int length = prices.length;
        if (null == prices || 0 == length)    return 0;
        int res = 0;
        int minVal = prices[0];
        for (int i = 1; i < length; i++){
            if (prices[i] < minVal){
                minVal = prices[i];
            }else{
                res = Math.max(res, prices[i] - minVal);
            }
        }
        return res;
    }
}
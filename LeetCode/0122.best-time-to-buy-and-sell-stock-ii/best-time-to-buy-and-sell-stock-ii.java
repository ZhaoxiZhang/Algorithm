class Solution {
    public int maxProfit(int[] prices) {
        int res = 0;
        int size = prices.length;
        for (int i = 0; i < size - 1; i++){
            if (prices[i + 1] > prices[i])  res += prices[i + 1] - prices[i];
        }
        return res;
    }
}
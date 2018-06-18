class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pque;
        for (int val : nums){
        	pque.push(val);
        }
        while (--k){
        	pque.pop();
        }
        return pque.top();
    }
};
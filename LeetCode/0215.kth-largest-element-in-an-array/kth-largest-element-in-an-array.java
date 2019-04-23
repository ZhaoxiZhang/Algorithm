class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer>pque = new PriorityQueue<>((o1, o2) -> o2 - o1);
        for (int i = 0; i < nums.length; i++){
            pque.add(nums[i]);
        }
        while (--k != 0){
            pque.poll();
        }
        return pque.peek();
    }
}
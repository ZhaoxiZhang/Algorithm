class Solution {
    fun removeElement(nums: IntArray, `val`: Int): Int {
        var move = 0
        for (index in nums.indices) {
            nums[index - move] = nums[index]
            if (nums[index] == `val`) {
                move++
            }
        }
        return nums.size - move
    }
}
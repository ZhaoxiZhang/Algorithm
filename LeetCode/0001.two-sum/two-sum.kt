class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val res = IntArray(2)
        val map = mutableMapOf<Int, Int>()
        for (i in nums.indices){
            map[nums[i]] = i
        }
        for (i in nums.indices){
            if (map[target - nums[i]] != null && i != map[target - nums[i]]){
                res[0] = map[target - nums[i]]!!
                res[1] = i
                break
            }
        }
        return res
    }
}
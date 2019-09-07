import kotlin.math.max

class Solution {
    fun lengthOfLongestSubstring(s: String): Int {
        val pos = IntArray(256)
        pos.fill(-1, 0, pos.size)
        var st = 0
        var res = 0
        for (i in s.indices) {
            val index = s[i].toInt()
            if (pos[index] == -1 || pos[index] < st) {
                res = max(res, i - st + 1)
            } else {
                st = pos[index] + 1
            }
            pos[index] = i
        }
        return res
    }
}
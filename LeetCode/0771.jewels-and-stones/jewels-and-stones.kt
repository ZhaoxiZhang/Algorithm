class Solution {
    fun numJewelsInStones(J: String, S: String): Int {
        val jHashMap = hashMapOf<Char, Boolean>()
        J.forEach { c ->
            jHashMap[c] = true
        }
        var res = 0
        S.forEach { c ->
            if (jHashMap[c] == true){
                res++
            }
        }
        return res
    }
}
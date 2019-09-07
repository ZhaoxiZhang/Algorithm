class Solution {
    fun reverse(x: Int): Int {
        var res = 0L
        var value : Int = x
        while (value != 0){
            res = res * 10 + value % 10
            value /= 10
        }
        if (res > Int.MAX_VALUE || res < Int.MIN_VALUE){
            return 0
        }
        return res.toInt()
    }
}
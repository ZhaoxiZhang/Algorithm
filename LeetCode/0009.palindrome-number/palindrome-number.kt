class Solution {
    fun isPalindrome(x: Int): Boolean {
        if (x < 0)  return false
        var value = x
        var sum = 0
        while (value != 0){
            sum = sum * 10 + value % 10
            value /= 10
        }
        return sum == x
    }
}
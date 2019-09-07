class Solution {
    fun repeatedNTimes(A: IntArray): Int {
        var first = A[0]
        var second = A[1]

        for (index in 2 until A.size) {
            if (A[index] == first || A[index] == second || A[index] == A[index - 1]) {
                return A[index]
            }
            first = second
            second = A[index]
        }

        return A[0]
    }
}
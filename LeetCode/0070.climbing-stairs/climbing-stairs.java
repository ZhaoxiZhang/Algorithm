class Solution {
    private int FibHelper(int n, int[] array){
        if (n < 3)  return n;
        else if (array[n] == 0){
            array[n] = FibHelper(n - 1, array) + FibHelper(n - 2, array);
        }
        return array[n];
    }

    public int climbStairs(int n) {
        int[] array = new int[n + 1];
        return FibHelper(n, array);
    }
}
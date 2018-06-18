class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int n = A.length;
        for (int i = 1;i < n - 1;i++){
            if (A[i] > A[i - 1] && A[i] > A[i + 1]){
                return i;
            }
        }
        return 1;
    }
}
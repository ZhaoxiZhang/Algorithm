public class Solution {
    public int minNumberInRotateArray(int [] array) {
        int left = 0,right = array.length - 1;
        while (left < right){
            int mid = left + (right - left) / 2;
            if (array[left] < array[mid]){
                left = mid;
            } else if (array[right] > array[mid]){
                right = mid;
            }else {
                break;
            }
        }
        return array[right];
    }
}
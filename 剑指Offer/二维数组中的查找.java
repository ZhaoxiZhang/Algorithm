public class Solution {
    public boolean Find(int target, int [][] array) {
        int m = array.length - 1;
        int n = array[0].length;
        int i = 0;
        while (m >= 0 && i < n){
            if (array[m][i] > target){
                m--;
            }else if (array[m][i] < target){
                i++;
            }else if (array[m][i] == target){
                return true;
            }
        }
        return false;
    }
}
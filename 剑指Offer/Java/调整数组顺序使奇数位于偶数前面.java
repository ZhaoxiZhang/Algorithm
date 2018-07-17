public class Solution {
    public void reOrderArray(int [] array) {
        int len = array.length;
        for (int i = 0;i < len - 1;i++){
            for (int j = 0;j < len - 1 - i;j++){
                if ((array[j] & 1) == 0 && (array[j + 1] & 1) == 1){
                    int tmp = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = tmp;
                }
            }
        }
    }
}
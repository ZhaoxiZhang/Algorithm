public class Solution {
    public int MoreThanHalfNum_Solution(int [] array) {
        int len = array.length;
        int val = array[0],cnt = 1;
        for (int i = 1;i < len;i++){
            if (val == array[i]){
                cnt++;
            }else{
                cnt--;
                if (cnt == 0){
                    val = array[i];
                    cnt = 1;
                    i++;
                }
            }
        }
        int sz = 0;
        for (int i = 0;i < len;i++){
            if (array[i] == val){
                sz++;
            }
        }
        if (2 * sz > len){
            return val;
        }else{
            return 0;
        }
    }
}
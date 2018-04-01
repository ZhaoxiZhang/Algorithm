public class Solution {
    public int JumpFloor(int target) {
        if (target == 0)    return 0;
        if (target == 1)    return 1;
        if (target == 2)    return 2;
        int a = 1;
        int b = 2;
        int cnt = 2;
        while (cnt < target){
            int tmp = b;
            b = a + b;
            a = tmp;
            cnt++;
        }
        return b;
    }
}
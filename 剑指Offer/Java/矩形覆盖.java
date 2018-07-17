public class Solution {
    public int RectCover(int target) {
        if (target == 0)    return 0;
        if (target == 1)    return 1;
        int one = 1;
        int two = 2;
        int cnt = 2;
        while (cnt < target){
            int tmp = two;
            two = one + two;
            one = tmp;
            cnt++;
        }
        return two;
    }
}
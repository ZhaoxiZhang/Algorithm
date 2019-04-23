class Solution {
    public int maxDistToClosest(int[] seats) {
        int[] left = new int[seats.length];
        int[] right = new int[seats.length];
        int r = 2 * seats.length - 1,l = -r;
        for (int i = 0;i < seats.length;i++){
            if (seats[i] == 0){
                left[i] = l;
            }else{
                left[i] = i;
                l = i;
            }
        }
        
        for (int i = seats.length - 1;i >= 0;i--){
            if (seats[i] == 0){
                right[i] = r;
            }else{
                right[i] = i;
                r = i;
            }
        }
        int res = 0;
        for (int i = 0;i < seats.length;i++){
            if (seats[i] == 0){
                res = Math.max(res,Math.min(i - left[i],right[i] - i));
            }
        }
        return res;
    }
}
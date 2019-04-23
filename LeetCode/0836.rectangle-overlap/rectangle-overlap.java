class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if (rec1[0] > rec2[0]){
            int[] tmp = rec1;
            rec1 = rec2;
            rec2 = tmp;
        }
        int xx1 = rec1[0],xy1 = rec1[1],xx2 = rec1[2],xy2 = rec1[3];
        int yx1 = rec2[0],yy1 = rec2[1],yx2 = rec2[2],yy2 = rec2[3];
        if (yx1 >= xx2 || yy1 >= xy2 || yy2 <= xy1){
            return false;
        }else{
            return true;
        }
    }
}
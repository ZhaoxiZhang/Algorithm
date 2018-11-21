class Solution {
    public boolean lemonadeChange(int[] bills) {
        int five = 0, ten = 0;
        int size = bills.length;
        for (int i = 0; i < size; i++){
            if (bills[i] == 5)  five++;
            else if (bills[i] == 10){
                ten++; five--;
            }
            else if (ten > 0){
                ten--; five--;
            }
            else five -= 3;
            if (five < 0)   return false;
        }
        return true;
    }
}
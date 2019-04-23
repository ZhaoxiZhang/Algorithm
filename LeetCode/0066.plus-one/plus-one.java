class Solution {
    public int[] plusOne(int[] digits) {
        int[] res;
        digits[digits.length - 1] += 1;
        int carry = digits[digits.length - 1] / 10;
        digits[digits.length - 1] %= 10;
        for (int i = digits.length - 2;i >= 0;i--){
            digits[i] = digits[i] + carry;
            carry = 0;
            if (digits[i] >= 10){
                carry = digits[i] / 10;
                digits[i] %= 10;
            }
        }
        if (carry != 0){
            res = new int[digits.length + 1];
            res[0] = carry;
            System.arraycopy(digits,0,res,1,digits.length);
        }else{
            res = new int[digits.length];
            System.arraycopy(digits,0,res,0,digits.length);
        }
        return res;
    }
}
//num1,num2分别为长度为1的数组。传出参数
//将num1[0],num2[0]设置为返回结果
public class Solution {
    public void FindNumsAppearOnce(int [] array,int num1[] , int num2[]) {
        int len = array.length;
        int diff = 0;
        for (int i = 0;i < len;i++){
            diff ^= array[i];
        }
        diff &= -diff; //lowbit
        for (int i = 0;i < len;i++){
            if ((array[i] & diff) == 0)   num1[0] ^= array[i];
            else    num2[0] ^= array[i];
        }
    }
}
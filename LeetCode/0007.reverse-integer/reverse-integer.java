class Solution {
    public int reverse(int x) {
        long reverseNum=0;
        while(x!=0){
            reverseNum=reverseNum*10+x%10;
            x/=10;
        }
        if(reverseNum>Integer.MAX_VALUE || reverseNum<Integer.MIN_VALUE){
            return 0;
        }
        return (int)reverseNum;
    }
}
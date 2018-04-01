class Solution {
    public String convert(String s, int numRows) {
        //List<String>list = new ArrayList<>();
        StringBuilder res = new StringBuilder();
        int len = 2 * numRows - 2;
        int strlen = s.length();
        for (int i = 0;i < numRows;i++){
            res.append(s.charAt(i));
            int pos = i;
            boolean flag = false;
            for (;pos < strlen;){
                if (flag && pos % len == 0){
                    pos += len - i*2;
                    res.append(s.charAt(pos));
                }else{
                    pos += 2*i;
                    res.append(s.charAt(pos));
                }
                flag = !flag;
            }
        }
        return res.toString();
    }
}
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1)   return s;
        StringBuilder stringBuilder = new StringBuilder();
        boolean[] vis = new boolean[s.length()];
        Arrays.fill(vis,false);
        int len = 2 * numRows - 2;
        int cnt = 0;
        for (int i = 0;i < numRows && i < s.length();i++){
            int j = i;
            stringBuilder.append(s.charAt(j));
            vis[j] = true;
            cnt++;
            boolean flag = true;
            while (j >= 0 && j < s.length()){
                if (flag){
                    j += len - 2 * i;
                    if (j >= 0 && j < s.length() && !vis[j]){
                        stringBuilder.append(s.charAt(j));
                        vis[j] = true;
                        cnt++;
                    }
                }else{
                    j += 2 * i;
                    if (j >= 0 && j < s.length() && !vis[j]){
                        stringBuilder.append(s.charAt(j));
                        vis[j] = true;
                        cnt++;
                    }
                }
                flag = !flag;
                if (cnt == s.length()){
                    break;
                }
            }
        }
        return stringBuilder.toString();
    }
}
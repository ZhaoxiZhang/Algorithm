class Solution {
    public List<String> letterCombinations(String digits) {
        List<String>res = new ArrayList<>();
        if (digits.contains("1") || digits.length() == 0)   return res;
        String[] str = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        func(str,digits,"",0,res);
        return res;
    }

    public void func(String[] str ,String digits,String string,int index,List<String>res){
        if (index >= digits.length()){
            res.add(string);
            return;
        }
        for (int i = 0;i < str[digits.charAt(index) - '2'].length();i++){
            func(str,digits,string + str[digits.charAt(index) - '2'].charAt(i),index + 1,res);
        }
    }
}
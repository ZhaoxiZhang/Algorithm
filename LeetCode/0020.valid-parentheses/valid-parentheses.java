class Solution {
    public boolean isValid(String s) {
        Stack<Character>stack = new Stack<>();
        Stack<Character>tmp = new Stack<>();
        for (int i = 0;i < s.length();i++){
            stack.push(s.charAt(i));
        }
        while (!stack.empty()){
            if (stack.peek() == ']' || stack.peek() == '}' || stack.peek() == ')'){
                tmp.push(stack.pop());
            }else{
                if (stack.peek() == '['){
                    if (!tmp.empty() && tmp.peek() == ']'){
                        tmp.pop();
                    }else{
                        return false;
                    }
                }else if (stack.peek() == '{'){
                    if (!tmp.empty() && tmp.peek() == '}'){
                        tmp.pop();
                    }else{
                        return false;
                    }
                }else if (stack.peek() == '('){
                    if (!tmp.empty() && tmp.peek() == ')'){
                        tmp.pop();
                    }else{
                        return false;
                    }
                }
                stack.pop();
            }
        }
        if (stack.empty() && tmp.empty()){
            return true;
        }else{
            return false;
        }
    }
}
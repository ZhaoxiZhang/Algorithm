class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        if (pushed == null) return true;
        Stack<Integer>push = new Stack<>();
        int popIndex = 0;
        for (int i = 0; i < pushed.length; i++){
            push.push(pushed[i]);
            while (!push.empty() && push.peek() == popped[popIndex]){
                push.pop();
                popIndex++;
            }
        }
        return push.empty() ? true : false;
    }
}
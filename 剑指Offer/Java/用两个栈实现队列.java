import java.util.Stack;
 
public class Solution {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();
 
    public void push(int node) {
        stack1.push(node);
    }
 
    public int pop() {
        while (stack1.isEmpty() == false){
            stack2.push(stack1.pop());
        }
        int val = stack2.pop();
        while (stack2.isEmpty() == false){
            stack1.push(stack2.pop());
        }
        return val;
    }
}
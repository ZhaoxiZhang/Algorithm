class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int res;
        while (!stack1.empty()){
            int data = stack1.top();
            stack2.push(data);
            stack1.pop();
        }
        res = stack2.top();
        stack2.pop();
        while (!stack2.empty()){
            int data = stack2.top();
            stack1.push(data);
            stack2.pop();
        }
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
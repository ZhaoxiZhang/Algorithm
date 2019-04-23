class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int size = pushed.size();
        stack<int>push;
        int popIndex = 0;
        for (int i = 0; i < size; i++){
            push.push(pushed[i]);
            while (!push.empty() && push.top() == popped[popIndex]){
                push.pop();
                popIndex++;
            }
        }

        return push.empty() ? true : false;
    }
};
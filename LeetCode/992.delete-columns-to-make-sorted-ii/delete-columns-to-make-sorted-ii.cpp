class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if (A.size() == 0)  return 0;
        int res = 0;
        map<int,int>mp;
        int size = A[0].size();
        for (int i = 0; i < size; i++){
            queue<int>que;
            
            for (int j = 1; j < A.size(); j++){
                if (mp[j] == 1) continue;
                
                if (A[j][i] > A[j - 1][i]){
                    que.push(j);
                }else if (A[j][i] < A[j - 1][i]){
                    res++;
                    while (!que.empty())    que.pop();
                    break;
                }
            }
            while (!que.empty())    mp[que.front()] = 1,que.pop();
        }
        return res;
    }
};
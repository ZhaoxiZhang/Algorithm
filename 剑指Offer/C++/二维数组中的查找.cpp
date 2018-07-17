class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size() - 1;
        int n = array[0].size();
        int i = 0;
        while (m >= 0 && i < n){
            if (array[m][i] > target){
                m--;
            }else if (array[m][i] < target){
                i++;
            }else{
                return true;
            }
        }
        return false;
    }
};
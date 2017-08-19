#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //13ms
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (unsigned i = 0;i < nums.size();i++){
            res ^= nums[i];
        }
        return res;
    }
};

int main(){
    int n,tmp;
    vector<int>nums;
    cin >> n;
    for (int i = 0;i < n;i++)   cin >> tmp, nums.push_back(tmp);
    Solution solution;
    cout << solution.singleNumber(nums) << endl;
    return 0;
}

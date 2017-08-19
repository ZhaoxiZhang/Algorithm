#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0,res = 0,i;
        for (i = 0;i < k;i++)  sum += nums[i];
        res = sum;
		for (;i < nums.size();i++){
			sum = sum - nums[i - k] + nums[i];
            res = max(res,sum);
        }
        return res / k;
    }
};

int main(){
	freopen("input.txt","r",stdin); 
    int n,tmp,k;
    vector<int>nums;
    cin >> n >> k;
    for (int i = 0;i < n;i++)   cin >> tmp,nums.push_back(tmp);
    Solution solution;
    cout << solution.findMaxAverage(nums,k) << endl;
    return 0;
}

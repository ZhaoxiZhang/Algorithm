#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //9ms
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int st = 0,ed = 0,sum = 0,res = len + 1;
        for (;;){
            while (ed < len && sum < s){
                sum += nums[ed++];
            }
            if (sum < s)	break;
            res = min(res,ed - st);
            sum -= nums[st++];
        }
        if (res == len + 1)	return 0;
        else	return res;
    }
};

int main(){
	int n,tmp;
	vector<int>nums;
	cin >> n;
	for (int i = 0;i < n;i++)	cin >> tmp,nums.push_back(tmp);
	Solution solution;
	cout << solution.minSubArrayLen(11,nums) << endl;
    return 0;
}

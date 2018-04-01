#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //13ms
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int res = 0;
        for (auto val : nums){
        	if (!s.count(val))	continue;
			int pre = --val,next = ++val;
        	while (s.count(pre))	s.erase(pre--);
        	while (s.count(next))	s.erase(next++);
			res = max(res,next - pre - 1);
        }
        return res;
    }
};

int main(){
	freopen("input.txt","r",stdin);
    vector<int>nums;
    int n,tmp;
    cin >> n;
    for (int i = 0;i < n;i++)   cin >> tmp,nums.push_back(tmp);
    //cout << nums.size() << endl;
    Solution solution;
    cout << solution.longestConsecutive(nums) << endl;
    return 0;
}

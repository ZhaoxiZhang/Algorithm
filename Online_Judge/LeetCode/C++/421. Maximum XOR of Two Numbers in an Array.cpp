#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //162ms
    int findMaximumXOR(vector<int>& nums) {
        int res = 0,mask = 0;
        for (int i = 31;i >= 0;i--){
            mask |= (1 << i);
            set<int>prefix;
            for (unsigned int i = 0;i < nums.size();i++){
                prefix.insert(nums[i] & mask);
            }
            int tmp = res | (1 << i);          //从高位枚举答案

            //set中的数相当于a、b，tmp相当于c，我们根据tmp和set中已有的一个数异或，
            //如果得到的数也在set中，说明这两个数异或能得到tmo值，然后用tmp更新res
            for (set<int>::iterator it = prefix.begin();it != prefix.end();it++){
                if (prefix.count(tmp^*it)){
                    res = tmp;
                    break;
                }
            }
        }
        return res;
    }
};

int main(){
	//freopen("input.txt","r",stdin);
    int n,tmp;
    vector<int>nums;
    cin >> n;
    for (int i = 0;i < n;i++)   cin >> tmp,nums.push_back(tmp);
    Solution solution;
    cout << solution.findMaximumXOR(nums) << endl;
    return 0;
}

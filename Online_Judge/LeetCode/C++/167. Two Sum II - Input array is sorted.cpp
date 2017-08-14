#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //6ms
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>res;
        int st = 0,ed = numbers.size() - 1;
        while (numbers[st] + numbers[ed] != target){
            if (numbers[st] + numbers[ed] > target) ed--;
            if (numbers[st] + numbers[ed] < target) st++;
        }
        res.push_back(st + 1);
        res.push_back(ed + 1);
        return res;
    }
};

int main(){
	freopen("input.txt","r",stdin);
    int n,tmp,target;
    vector<int>numbers;
    cin >> n >> target;
    for (int i = 0;i < n;i++){
        cin >> tmp;
        numbers.push_back(tmp);
    }
    Solution solution;
    vector<int>res = solution.twoSum(numbers,target);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}

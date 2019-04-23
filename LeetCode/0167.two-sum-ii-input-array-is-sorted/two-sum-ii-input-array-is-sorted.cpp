class Solution {
public:
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
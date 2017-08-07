class Solution {
public:
	
	//12ms 
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        map<int,int>mp;
        for (unsigned int i = 0;i < nums.size();i++){
            mp[nums[i]] = i;
        }
        for (unsigned int i = 0;i < nums.size();i++){
            if (mp.find(target - nums[i]) != mp.end() && i != mp[target - nums[i]]){
                res.push_back(i);
                res.push_back(mp[target-nums[i]]);
                return res;
            }
        }
    }
    
    //6ms
    vector<int> twoSum(vector<int> &numbers, int target){

        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++){
            int numberToFind = target - numbers[i];


            if (hash.find(numberToFind) != hash.end()){
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;
            }
            hash[numbers[i]] = i;
        }
        return result;
    }
};

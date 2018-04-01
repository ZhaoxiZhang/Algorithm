class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s(nums1.begin(),nums1.end()),ans;
        for (unsigned i = 0;i < nums1.size();i++)   s.insert(nums1[i]);
        for (unsigned i = 0;i < nums2.size();i++){
            if (s.count(nums2[i])){
                ans.insert(nums2[i]);
            }
        }
        return vector<int>(ans.begin(),ans.end());
    }
};
class Solution {
private:
    int Media3(vector<int> &nums, int left, int right) {
        int center = (left + right) >> 1;

        if (nums[left] < nums[center])  swap(nums[left], nums[center]);
        if (nums[left] < nums[right])   swap(nums[left], nums[right]);
        if (nums[center] < nums[right]) swap(nums[center], nums[right]);

        swap(nums[center], nums[left + 1]);

        return nums[left + 1];
    }

    void Kth(vector<int> &nums, int left, int right, int k) {
        int i, j, pivot;

        if (left > right || left > k)   return;

        //pivot = Media3(nums, left, right);
        pivot = nums[left];
		i = left;
        j = right;

        while (i != j) {
        	while (nums[j] <= pivot && i < j)	j--;
        	while (nums[i] >= pivot && i < j)	i++;
        	if (i < j)	swap(nums[i], nums[j]);
        }
        //restore pivot
        nums[left] = nums[i];
        nums[i] = pivot;

        Kth(nums, left, i - 1, k);
        Kth(nums, i + 1, right, k);
    }
public:
    int findKthLargest(vector<int> &nums, int k) {

        Kth(nums, 0, nums.size() - 1, k - 1);

        return nums[k - 1];
    }
};
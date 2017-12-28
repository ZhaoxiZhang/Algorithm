public class Solution {
    //76ms
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>>res = new ArrayList<>();
        int len = nums.length;
        if (len < 3){
            return res;
        }

        Arrays.sort(nums);
        if (3 * nums[0] > 0){
            return res;
        }

        for (int i = 0;i < len;i++){
            int max = nums[len - 1];
            int z = nums[i];
            if (i > 0 && nums[i - 1] == z){
                continue;
            }
            if (z + 2 * max < 0){
                continue;
            }
            if (3 * z > 0){
                break;
            }
            if (3 * z == 0){
                if (i + 2 < len && nums[i + 2] == z){
                    res.add(Arrays.asList(z,z,z));
                }
            }
            twoSum(0 - z,i + 1,len - 1,nums,res,z);
        }

        return res;
    }

    public void twoSum(int target,int left,int right,int[] nums,List<List<Integer>>res,int z1){
        while (left <= right && z1 == 0 && nums[left] == z1){
            left++;
        }
        if (left >= right){
            return;
        }
        int max = nums[right];
        int z = nums[left];
        if (2 * z > target){
            return;
        }
        if (2 * max < target){
            return ;
        }
        while (left < right){
            int sum = nums[left] + nums[right];
            if (sum == target){
                res.add(Arrays.asList(z1,nums[left],nums[right]));

                while (++left < right && nums[left] ==nums[left - 1]){}
                while (--right > left && nums[right] == nums[right + 1]){}

            }

            if (sum < target){
                left++;
            }

            if (sum > target){
                right--;
            }
        }
    }




    //72ms
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>>res = new ArrayList<>();
        int len = nums.length;
        Arrays.sort(nums);
        for (int i = 0;i < len - 2;i++){
            int sum = -nums[i];
            int left = i + 1,right = len - 1;
            while (left < right){
                if (nums[left] + nums[right] < sum){
                    left++;
                } else if (nums[left] + nums[right] > sum){
                    right--;
                } else{
                    res.add(Arrays.asList(nums[i],nums[left],nums[right]));
                    while (++left < right && nums[left] == nums[left - 1]){}
                    while (--right > left && nums[right] == nums[right + 1]){}
                }
            }
            while (i + 1 < len - 2 && nums[i + 1] == nums[i]){
                i++;
            }
        }
        return res;
    }

}

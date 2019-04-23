public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len = nums1.length + nums2.length;
        if ((len  & 1) == 1){
            return findKth(nums1,nums2,len / 2 + 1);
        }
        else{
            return (findKth(nums1,nums2,len / 2) + findKth(nums1,nums2,len / 2 + 1)) / 2;
        }
    }

    public double findKth(int[] nums1, int[] nums2,int k){
        int len1 = nums1.length,len2 = nums2.length;
        if (len1 > len2)    return findKth(nums2,nums1,k);
        if (len1 == 0)   return nums2[k - 1];
        if (k == 1) return Math.min(nums1[0],nums2[0]);
        int a = Math.min(k / 2,len1),b = k - a;
        if (nums1[a - 1] < nums2[b - 1])   return findKth(Arrays.copyOfRange(nums1, a, len1),nums2,k - a);
        else    if (nums1[a - 1] > nums2[b - 1])    return findKth(nums1,Arrays.copyOfRange(nums2,b,len2), k - b);
        else    return nums1[a - 1];
    }
}
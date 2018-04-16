class Solution {
    public int maxArea(int[] height) {
        int len = height.length;
        int left = 0,right = len - 1;
        int h,area = 0;
        while (left < right){
            h = Math.min(height[left],height[right]);
            area = Math.max(area,h * (right - left));

            if (height[left] == h)  left++;
            if (height[right] == h) right--;
        }
        return area;
    }
}
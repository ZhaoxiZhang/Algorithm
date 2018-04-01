class Solution {
    //10ms
    public int maxArea(int[] height) {
        int len = height.length;
        int left = 0,right = len - 1;
        int h,area,max = 0;
        while (left < right){
            h = min(height[left],height[right]);
            area = max(area,h * (right - left));

            if (height[left] == h)  left++;
            if (height[right] == h) right--;
        }
        return area;
    }
}
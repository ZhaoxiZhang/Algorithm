class Solution {
    public int findMinArrowShots(int[][] points) {
        if (null == points || 0 == points.length)   return 0;
        int res = 1;
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return a[1] - b[1];
            }
        });
        int end = points[0][1];
        for (int i = 1;i < points.length; i++){
            if (points[i][0] <= end)    continue;
            res++;
            end = points[i][1];
        }
        return res;
    }
}
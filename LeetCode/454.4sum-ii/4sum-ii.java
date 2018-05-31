class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int res = 0;
        int[] sum = new int[C.length * D.length];
        for (int i = 0;i < C.length;i++){
            for (int j = 0;j < D.length;j++){
                sum[i * D.length + j] = C[i] + D[j];
            }
        }
        Arrays.sort(sum,0,C.length * D.length);
        for (int i = 0;i < A.length;i++){
            for (int j = 0;j < B.length;j++){
                int key = -A[i] - B[j];
                res += upper_bound(sum,key) - lower_bound(sum,key);
            }
        }
        return res;
    }

    public int upper_bound(int[] array,int key){
        int left = 0,right = array.length - 1;
        while (left < right){
            int mid = left + (right - left) / 2;
            if (array[mid] <= key){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return array[right] > key ? right : right + 1;
    }

    public int lower_bound(int[] array,int key){
        int left = 0,right = array.length - 1;
        while (left < right){
            int mid = left + (right - left) / 2;
            if (array[mid] >= key){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return array[left] < key ? left + 1 : left;
    }
}
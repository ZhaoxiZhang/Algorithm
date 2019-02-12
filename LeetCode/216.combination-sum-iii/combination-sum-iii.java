class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>>res = new ArrayList<>();
        int[] num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        solver(res, num, new ArrayList<>(), k, n, 0, 0);
        return res;
    }

    public void solver(List<List<Integer>>res, int[] num, List<Integer>tmp, int k, int target, int stIndex, int cnt){
        if (cnt == k){
            if (target == 0)    res.add(new ArrayList<>(tmp));
        }else{
            for (int i = stIndex; i < 9; i++){
                if (target - num[i] < 0)    break;
                tmp.add(num[i]);
                solver(res, num, tmp, k, target - num[i], i + 1, cnt + 1);
                tmp.remove(tmp.size() - 1);
            }
        }
    }
}
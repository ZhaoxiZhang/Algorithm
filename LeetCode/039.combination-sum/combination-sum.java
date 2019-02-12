class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>>res = new ArrayList<>();
        Arrays.sort(candidates);
        solver(res, candidates, new ArrayList<>(), target, 0);
        return res;
    }

    public void solver(List<List<Integer>>res, int[] candidates, List<Integer>tmp, int target, int stIndex){
        if (target < 0) return;
        else if (target == 0)    res.add(new ArrayList<>(tmp));
        else 
        for (int i = stIndex; i < candidates.length; i++){
            tmp.add(candidates[i]);
            if (target - candidates[i] < 0) break;
            solver(res, candidates, new ArrayList<>(tmp), target - candidates[i], i);
            tmp.remove(tmp.size() - 1);
        }
    }
}
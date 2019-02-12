class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>>res = new ArrayList<>();
        Arrays.sort(candidates);
        solver(res, candidates, new ArrayList<>(), target, 0);
        return res;
    }

    public void solver(List<List<Integer>>res, int[] candidates, List<Integer>tmp, int target, int stIndex){
        if (target < 0) return;
        else if (target == 0)   res.add(new ArrayList<>(tmp));
        else
            for (int i = stIndex; i < candidates.length; i++){
                if (i > stIndex && candidates[i] == candidates[i - 1])  continue;
                if (target - candidates[i] < 0) break;
                tmp.add(candidates[i]);
                solver(res, candidates, tmp, target - candidates[i], i + 1);
                tmp.remove(tmp.size() - 1);
            }
    }
}
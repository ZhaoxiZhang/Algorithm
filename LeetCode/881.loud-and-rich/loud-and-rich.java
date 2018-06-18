class Solution {
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        int[] res = new int[quiet.length];
        Arrays.fill(res,-1);
        HashMap<Integer,List<Integer>>mp = new HashMap<>();
        for (int i = 0;i < quiet.length;i++){
            mp.put(i,new ArrayList<>());
        }
        for (int[] per : richer){
            mp.get(per[1]).add(per[0]);
        }
        for (int i = 0;i < quiet.length;i++){
            dfs(mp,i,quiet,res);
        }
        return res;
    }

    public void dfs(HashMap<Integer,List<Integer>>mp,int index,int[] quiet,int[] res){
        if (res[index] >= 0)    return;
        res[index] = index;
        for (int val : mp.get(index)){
            dfs(mp,val,quiet,res);
            if (quiet[res[val]] < quiet[res[index]]){
                res[index] = res[val];
            }
        }
    }
}
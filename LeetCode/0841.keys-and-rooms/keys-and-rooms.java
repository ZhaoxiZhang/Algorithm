class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        Stack<Integer>stk = new Stack<>();
        stk.add(0);
        boolean[] vis = new boolean[rooms.size()];
        Arrays.fill(vis,false);
        vis[0] = true;
        while (!stk.empty()){
            int index = stk.pop();
            for (int val : rooms.get(index)){
                if (!vis[val]){
                    stk.add(val);
                    vis[val] = true;
                }
            }
        }
        for (boolean val : vis){
            if (!val){
                return false;
            }
        }
        return true;
    }
}
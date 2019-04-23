class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int length = gas.length;
        int res = -1;
        for (int i = 0; i < length; i++){
            int index = i;
            int oil = 0;
            if (gas[index] >= cost[index]){
                while (oil >= 0){
                    oil += gas[index] - cost[index];
                    index = (index + 1) % length;
                    if (index == i){
                        if (oil >= 0)   res = i;
                        break;
                    }
                }
                if (res != -1 || index <= i)    break;
                index--;
            }
            i = index;
        }
        return res;
    }
}
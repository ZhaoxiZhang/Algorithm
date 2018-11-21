class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int size = gas.size();
            int res = -1;
            for (int i = 0; i < size; i++){
                int index = i;
                int oil = 0;
                if (gas[index] >= cost[index]){
                    while (oil >= 0){
                        oil += gas[index] - cost[index];
                        index = (index + 1) % size;
                        if (index == i){
                            if (oil >= 0)   res = i;
                            break;
                        }
                    }
                    if (res != -1 || index <= i) break;
                    index--;
                }
                i = index;
            }
            return res;
        }
};
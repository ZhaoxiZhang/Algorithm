class Solution {
    public int minIncrementForUnique(int[] A) {
        if (A == null || A.length == 0) return 0;
        Arrays.sort(A);
        List<Integer>list = new ArrayList<>();
        Map<Integer,Integer>map = new HashMap<>();
        int val = A[0];
        for (int i = 1; i < A.length; i++){
            map.put(A[i], 1);
            if (A[i] == val)    list.add(val);
            else    val = A[i];
        }
        int res = 0;
        if (list.size() == 0)   res = 0;
        else{
            int index = list.get(0);
            for (int i = 0; i < list.size(); i++){
                val = list.get(i);
                index = index < val ? val : index;
                while (map.get(index) != null && map.get(index) == 1) index++;
                map.put(index, 1);
                res += index - val;
            }
        }
        return res;
    }
}
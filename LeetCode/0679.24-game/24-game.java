class Solution {
    boolean res = false;
    final double esp = 1e-4;
    public boolean judgePoint24(int[] nums) {
        List<Double>list = new ArrayList<Double>();
        for (int val:nums)  list.add((double)val);
        solver(list);
        return res;
    }

    void solver(List<Double> array){
        if (res)    return;
        if (array.size() == 1 && Math.abs(array.get(0) - 24.0) <= esp){
            res = true;
            return;
        }

        for (int i = 0;i < array.size();i++){
            for (int j = 0;j < i;j++){
                List<Double>list = new ArrayList<Double>();
                Double p1 = array.get(i),p2 = array.get(j);
                list.addAll(Arrays.asList(p1+p2,p1-p2,p2-p1,p1*p2));
                if (Math.abs(p1) > esp){
                    list.add(p2/p1);
                }
                if (Math.abs(p2) > esp){
                    list.add(p1/p2);
                }

                array.remove(i);
                array.remove(j);

                for (Double val:list){
                    array.add(val);
                    solver(array);
                    array.remove(val);
                }

                array.add(j,p2);
                array.add(i,p1);

            }
        }
    }
}
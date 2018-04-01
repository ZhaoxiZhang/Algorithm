public class Solution {
    //method1
//    private int sz = 0;
//    public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
//        ArrayList<Integer>res = new ArrayList<>();
//        if (k > input.length)   return res;
//        sz = 0;
//        int heap[] = new int[input.length];
//        for (int i = 0;i < input.length;i++){
//            push(heap,input[i]);
//        }
//        for (int i = 0;i < k;i++){
//            res.add(pop(heap));
//        }
//        return res;
//    }
//
//    public int pop(int [] heap){
//        int ret = heap[0];
//        int x = heap[--sz];
//        int i = 0;
//        while (2 * i + 1 < sz){
//            int a = 2 * i + 1;
//            int b = 2 * i + 2;
//            if (b < sz && heap[b] < heap[a])    a = b;
//            if (x < heap[a])    break;
//            heap[i] = heap[a];
//            i = a;
//        }
//        heap[i] = x;
//        return ret;
//    }
//
//    public void push(int [] heap,int x){
//        int i = sz++;
//        while (i > 0){
//            int p = (i - 1) / 2;
//            if (heap[p] <= x)   break;
//            heap[i] = heap[p];
//            i = p;
//        }
//        heap[i] = x;
//    }

    //method2
//    public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
//        ArrayList<Integer>res = new ArrayList<>();
//        if (k > input.length || k == 0)   return res;
//        PriorityQueue<Integer>pque = new PriorityQueue<>(k, new Comparator<Integer>() {
//            @Override
//            public int compare(Integer o1, Integer o2) {
//                return o2.compareTo(o1);
//            }
//        });
//        for (int i = 0;i < k;i++){
//            pque.offer(input[i]);
//        }
//
//        for (int i = k;i < input.length;i++){
//            int val = pque.peek();
//            if (input[i] < val){
//                pque.poll();
//                pque.offer(input[i]);
//            }
//        }
//
//        while (!pque.isEmpty()){
//            res.add(pque.poll());
//        }
//        return res;
//    }
}
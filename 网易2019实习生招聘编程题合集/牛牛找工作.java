import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static int maxn = 100005;
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int N,M;
        int[] res = new int[maxn];
        Pir[] thg = new Pir[maxn];
        Node[] peo = new Node[maxn];
        N = scanner.nextInt();
        M = scanner.nextInt();
        for (int i = 0;i < N;i++){
            thg[i] = new Pir();
            thg[i].Di = scanner.nextInt();
            thg[i].Pi = scanner.nextInt();
        }
        for (int i = 0;i < M;i++){
            peo[i] = new Node();
            peo[i].A = scanner.nextInt();
            peo[i].index = i;
        }
        Arrays.sort(thg,0,N, new Comparator<Pir>() {
            @Override
            public int compare(Pir o1, Pir o2) {
                return o1.Di - o2.Di;
            }
        });
        Arrays.sort(peo,0,M, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.A - o2.A;
            }
        });
        int Dindex = 0;
        for (int i = 0;i < M;i++){
            if (i != 0) res[peo[i].index] = res[peo[i - 1].index];
            while (Dindex < N && thg[Dindex].Di <= peo[i].A){
                if (res[peo[i].index] < thg[Dindex].Pi){
                    res[peo[i].index] = thg[Dindex].Pi;
                }
                Dindex++;
            }
        }
        for (int i = 0;i < M;i++){
            System.out.println(res[i]);
        }
    }
}

class Node{
    public int A,index;
}

class Pir{
    public int Di,Pi;
}

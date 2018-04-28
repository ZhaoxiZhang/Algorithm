import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int left,right;
        left = scanner.nextInt();
        right = scanner.nextInt();
        int res = 0;
        for (int i = left;i <= right;i++){
            switch (i % 3){
                case 0:res++;break;
                case 1:break;
                case 2:res++;break;
            }
        }
        System.out.println(res);
    }
}
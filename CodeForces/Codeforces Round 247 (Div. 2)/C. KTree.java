import java.util.*;
import static java.lang.System.out;

public class KTree {
    static final int MOD = (int) (1e9+7);
    public static void main(String[] args){
        long[][] dp = new long[105][2];
        int n,k,d;
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        k = scan.nextInt();
        d = scan.nextInt();
        dp[0][0] = 1;
        for (int i = 0;i <= n;i++){
            for (int j = 1;j <= k;j++){
                if (i + j > n)  continue;

                if (j < d)  dp[i + j][0] += dp[i][0];
                else dp[i + j][1] += dp[i][0];

                dp[i + j][1] += dp[i][1];

                dp[i + j][0] %= MOD;
                dp[i + j][1] %= MOD;
            }
        }
        out.println(dp[n][1]);
    }
}

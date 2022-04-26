import java.util.Arrays;

public class CoinChange {
    public static void main(String[] args) {
        Integer[] coins = {1, 2, 5, 20};
        Integer S = 11;
        System.out.println(coinchange(coins, S));
    }

    /**
     * coins=[c1,c2,...,cm]
     * f(x)=min{f(x-c1),f(x-c2),...,f(x-cm)}+1
     * 如果x-ci<0, 那么f(x-ci)取成正无穷
     * 如果x-c=0, 那么f(x-ci)=0，即f(0)=0
     */
    public static int coinchange(Integer[] coins, Integer S) {
        Integer[] dp = new Integer[S + 2];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for (int i = 1; i <= S; ++i) {
            Integer[] tmp = laststep(i, coins);
            dp[i] = minCoins(dp, tmp);
        }

        if (dp[S] == Integer.MAX_VALUE) {
            return -1;
        } else {
            return dp[S];
        }
    }

    public static Integer[] laststep(Integer S, Integer[] coins) {
        Integer[] tmp = new Integer[coins.length];
        for (int i = 0; i < coins.length; ++i) {
            tmp[i] = S - coins[i];
        }
        return tmp;
    }

    public static Integer minCoins(Integer[] dp, Integer[] index) {
        Integer minvalue = Integer.MAX_VALUE;
        for (int i = 0; i < index.length; ++i) {
            if (index[i] < 0) {
                index[i] = dp.length - 1;
            }
            minvalue = Integer.min(minvalue, dp[index[i]]);
        }
        if (minvalue == Integer.MAX_VALUE) {
            return Integer.MAX_VALUE;
        } else {
            return minvalue + 1;
        }
    }

}

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class 礼品的最大价值 {
    public static void main(String[] args) {
        List<List<Integer>> M = new ArrayList<>();
        List<Integer> tmp1 = new ArrayList<>(Arrays.asList(5, 1, 5, 1));
        List<Integer> tmp2 = new ArrayList<>(Arrays.asList(3, 5, 3, 5));
        List<Integer> tmp3 = new ArrayList<>(Arrays.asList(4, 2, 1, 1));
        List<Integer> tmp4 = new ArrayList<>(Arrays.asList(1, 5, 1, 3));
        List<Integer> tmp5 = new ArrayList<>(Arrays.asList(1, 5, 3, 4));
        M.add(tmp1);
        M.add(tmp2);
        M.add(tmp3);
        M.add(tmp4);
        M.add(tmp5);

        System.out.println(maxGiftValue(M));
    }

    public static int maxGiftValue(List<List<Integer>> M) {
        if (M.size() == 1) {
            int ret = 0;
            for (int i = 0; i < M.get(0).size(); ++i) {
                ret += M.get(0).get(i);
            }
            return ret;
        } else if (M.get(0).size() == 1) {
            int ret = 0;
            for (int i = 0; i < M.size(); ++i) {
                ret += M.get(i).get(0);
            }
            return ret;
        } else {
            Integer[][] dp = arr(M);
            {
                Integer tmp = 0;
                for (int i = 0; i < M.get(0).size(); ++i) {
                    tmp += M.get(0).get(i);
                    dp[0][i] = tmp;
                }
                tmp = 0;
                for (int i = 0; i < M.size(); ++i) {
                    tmp += M.get(i).get(0);
                    dp[i][0] = tmp;
                }
            }

            for (int i = 1; i < M.size(); ++i) {
                for (int j = 1; j < M.get(0).size(); ++j) {
                    int tmp1 = dp[i - 1][j] + M.get(i).get(j);
                    int tmp2 = dp[i][j - 1] + M.get(i).get(j);
                    dp[i][j] = Math.max(tmp1, tmp2);
                }
            }
            print(dp);
            System.out.println();

            Integer[][] path = arr(M);
            int i = M.size() - 1;
            int j = M.get(0).size() - 1;
            path[i][j] = 1;
            while (i != 0 && j != 0) {

                if (dp[i - 1][j] < dp[i][j - 1]) {
                    path[i][j - 1] = 1;
                    --j;
                } else {
                    path[i - 1][j] = 1;
                    --i;
                }
            }

            if(i==0){
                for(int l=j;l>=0;--l){
                    path[i][l] = 1;
                }
            }else {
                for(int l=i;l>=0;--l){
                    path[l][j] = 1;
                }
            }

            print(path);


            return dp[M.size() - 1][M.get(0).size() - 1];
        }
    }

    public static Integer[][] arr(List<List<Integer>> M) {
        Integer[][] tmp = new Integer[M.size()][M.get(0).size()];
        for (int i = 0; i < M.size(); ++i) {
            for (int j = 0; j < M.get(0).size(); ++j) {
                tmp[i][j] = 0;
            }
        }
        return tmp;
    }

    public static void print(Integer[][] tmp) {
        for (Integer[] integers : tmp) {
            for (Integer integer : integers) {
                System.out.printf("%d\t", integer);
            }
            System.out.println();
        }
    }
}

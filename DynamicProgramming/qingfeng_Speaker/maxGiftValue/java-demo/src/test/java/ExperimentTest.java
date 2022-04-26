import org.junit.Test;

import java.util.Arrays;

class ExperimentTest {
    @Test
    public void test1(){
        Integer[][] dp=new Integer[3][4];
        Integer[] tmp=new Integer[4];
        Arrays.fill(tmp,-1);
        Arrays.fill(dp,tmp);
        for (int i=0;i<3;++i){
            for (int j=0; j<4;++j){
                System.out.printf("%d  ", dp[i][j]);
            }
            System.out.println();
        }
    }
}

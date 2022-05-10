#include<iostream>
#include<vector>
using namespace std;
/**
 * 递归是自顶向下搜索，然后自底向上相加，我们可以直接用自底向上相加。
 * 用动态规划的方法，dp[i][j]表示i个苹果分在j个盘子中的分法，首先苹果数为0即i=0全部初始化为1,
 * 然后遍历二维数组将dp数组填满，当i小于j的时候，苹果数少于盘子数，则等于它前一个盘子时的分法，
 * 因为这个盘子相当于常空着，没有用；当i大于等于j的时候，苹果数大于等于盘子数，
 * 则它等于上一个盘子的数量（即相当于至少有这个盘子是空的）加上苹果数减去盘子数且盘子数不变时
 * 的分法（即相当于每个盘子都有，排除这些后的分法）。
 * */
int main(){
    int m, n;
    while(cin >> m >> n){
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); //dp[i][j]表示i个苹果放在j个盘子的分法
        for(int i = 1; i <= n; i++)
            dp[0][i] = 1; //0个苹果只有1种分法
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++){
                if(i < j)
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            }
        cout << dp[m][n] << endl;
    }
    return 0;
}
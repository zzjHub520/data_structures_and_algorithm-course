// package org.jzy.huawei108;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            // 初始化数字数组和标志数组
            int[] nums = new int[4];
            int[] signs = new int[4];
            for (int i = 0; i < nums.length; i++) {
                nums[i] = scanner.nextInt();
            }

            boolean can = false; // 是否能得到24
            for (int i = 0; i < nums.length; i++) {
                signs[i] = 1;
                if (dfs(nums, signs, nums[i], 24)) {
                    can = true;
                    break;
                }
                signs[i] = 0;
            }
            System.out.println(can);// 输出结果
        }
    }

    /**
     * 深度优先算法逻辑
     *
     * @param nums     输入的4个数字
     * @param signs    访问标志数组
     * @param v        顶点的值
     * @param required 需要通过四则运算得到的数字
     * @return
     */
    private static boolean dfs(int[] nums, int[] signs, int v, int required) {
        boolean allVisited = true;// 四个角均被访问
        for (int sign : signs) {
            if (sign == 0) {
                allVisited = false;
            }
        }

        if (allVisited) {
            return v == required; // 在所有节点均被访问的前提下，判断最后的结果是否为所需要的结果。
        }

        // 访问所有的邻接顶点
        for (int i = 0; i < nums.length; i++) {
            if (signs[i] == 0) {
                signs[i] = 1;
                if (dfs(nums, signs, v + nums[i], required) // 加法
                        || dfs(nums, signs, v - nums[i], required) // 减法
                        || dfs(nums, signs, v * nums[i], required) // 乘法
                        || nums[i] != 0 && v % nums[i] == 0 && dfs(nums, signs, v / nums[i], required)/* 除法 */) {
                    return true;// 如果可以通过四则运算得到需要的结果，则返回true。
                }
                signs[i] = 0; // 如果不能通过四则运算得到，则进行回溯。
            }
        }

        return false;//当所有情况均得不到需要的结果，返回false。
    }
}
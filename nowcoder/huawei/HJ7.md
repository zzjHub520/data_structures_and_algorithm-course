HJ7 取近似值







- 题目
- 题解(341)
- 讨论(1k)
- 排行

入门 通过率：50.81% 时间限制：1秒 空间限制：32M

知识点[基础数学](https://www.nowcoder.com/exam/oj/ta?tpId=37?tag=5050)[语法题](https://www.nowcoder.com/exam/oj/ta?tpId=37?tag=5165)

![warning](https://static.nowcoder.com/fe/file/images/web/ta/warning.png) 校招时部分企业笔试将禁止编程题跳出页面，为提前适应，练习时请使用在线自测，而非本地IDE。

## 描述

写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于 0.5 ,向上取整；小于 0.5 ，则向下取整。

数据范围：保证输入的数字在 32 位浮点数范围内

### 输入描述：

输入一个正浮点数值

### 输出描述：

输出该数值的近似整数值

## 示例1

输入：

```
5.5
```

复制

输出：

```
6
```

复制

说明：

```
0.5>=0.5，所以5.5需要向上取整为6   
```

## 示例2

输入：

```
2.499
```

复制

输出：

```
2
```

复制

说明：

```
0.499<0.5，2.499向下取整为2   
```

相似企业真题
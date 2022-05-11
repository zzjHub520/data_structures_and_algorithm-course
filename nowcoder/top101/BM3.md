[![img](MarkDownImages/BM3.assets/resize,m_mfit,h_200,w_200.png)](https://www.nowcoder.com/profile/2127843)

BM3 链表中的节点每k个一组翻转







- 题目
- 题解(241)
- 讨论(315)
- 排行

中等 通过率：40.50% 时间限制：1秒 空间限制：64M

知识点[链表](https://www.nowcoder.com/exam/oj?page=1&tab=算法篇&topicId=295?tag=580)

## 描述

将给出的链表中的节点每 k 个一组翻转，返回翻转后的链表
如果链表中的节点数不是 k 的倍数，将最后剩下的节点保持原样
你不能更改节点中的值，只能更改节点本身。

数据范围： \ 0 \le n \le 2000 0≤*n*≤2000 ， 1 \le k \le 20001≤*k*≤2000 ，链表中每个元素都满足 0 \le val \le 10000≤*v**a**l*≤1000
要求空间复杂度 O(1)*O*(1)，时间复杂度 O(n)*O*(*n*)

例如：

给定的链表是 1\to2\to3\to4\to51→2→3→4→5

对于 k = 2*k*=2 , 你应该返回 2\to 1\to 4\to 3\to 52→1→4→3→5

对于 k = 3*k*=3 , 你应该返回 3\to2 \to1 \to 4\to 53→2→1→4→5

## 示例1

输入：

```
{1,2,3,4,5},2
```

复制

返回值：

```
{2,1,4,3,5}
```

复制

## 示例2

输入：

```
{},1
```

复制

返回值：

```
{}
```

复制

关联企业
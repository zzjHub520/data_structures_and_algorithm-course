BM1 反转链表







- 题目
- 题解(674)
- 讨论(2k)
- 排行

简单 通过率：38.85% 时间限制：1秒 空间限制：64M

知识点[链表](https://www.nowcoder.com/exam/oj?tag=580)

## 描述

给定一个单链表的头结点pHead(该头节点是有值的，比如在下图，它的val是1)，长度为n，反转该链表后，返回新链表的表头。

数据范围： 0\leq n\leq10000≤*n*≤1000

要求：空间复杂度 O(1)*O*(1) ，时间复杂度 O(n)*O*(*n*) 。

如当输入链表{1,2,3}时，

经反转后，原链表变为{3,2,1}，所以对应的输出为{3,2,1}。

以上转换过程如下图所示：

![img](MarkDownImages/BM1.assets/4A47A0DB6E60853DEDFCFDF08A5CA249.png)

## 示例1

输入：

```
{1,2,3}
```

复制

返回值：

```
{3,2,1}
```

复制

## 示例2

输入：

```
{}
```

复制

返回值：

```
{}
```

复制

说明：

```
空链表则输出空                  
```

关联企业
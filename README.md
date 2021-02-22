# STLite-2021
CS1951 assignment, ACM Class, SJTU

## 实现要求

要求实现与C++标准库类似的数据结构，包括迭代器等。框架接口在已本仓库中给出，只需要实现`.hpp`文件内所要求的内容即可。

请注意，在本作业中，只允许使用`cstdio`，`cstring`，`iostream`，`cmath`四个C++标准库，如需使用其他功能请自行实现。在下发代码中有`exceptions.hpp`和`utility.hpp`两个辅助文件，你需要使用其中的异常处理和`sjtu::pair`完成STLite的实现，但不允许修改其中的任何内容。

A班要求完成`sjtu::priority_queue`、`sjtu::deque`和`sjtu::map`，B班要求完成`sjtu::vector`、`sjtu::deque`和`sjtu::map`。

本作业中的四个容器在接口和复杂度要求上与STL基本一致，除了：

#### 与STL的不同之处

- `sjtu::priority_queue`要求以最高$O(\log n)$的时间复杂度实现合并操作。
- `sjtu::deque`要求支持以不超过$O(\sqrt n)$时间完成**任意位置**的插入和删除，但随机访问的时间复杂度要求降低为$O(\sqrt n)$。
- `sjtu::deque`的迭代器在首尾操作后也会失效。
- `sjtu::map`的实现B班要求平衡化（可使用AVL树、红黑树、AA树等），A班要求使用红黑树完成。

因此，如果对内容有任何疑问，可以参考STL，或是在这里提出issue，谢谢！

最后，我们会检查内存泄漏，如果还不会测内存泄漏，可以看教程[如何检测内存泄漏？](./tutorials/detect-memory-leak/detect-memory-leak.md)


## 评测方法

测试数据将全部下发（见本仓库），供调试使用。最终测试将会在OJ上进行，并进行code review。

## 分数构成

在 OJ 上通过测试数据可获得 80% 的分数，code review 占 20% 的分数。

## 截止日期

`priority_queue`(A)/`vector`(B)：3月10日（第三周周三）23:00前

`deque`：3月31日（第六周周三）23:00前

`map`：4月28日（第十周周三）23:00前

## 迟交惩罚

迟交第i天(向上取整)，扣除i*10%的分数，扣完为止。

每一道题独立统计。

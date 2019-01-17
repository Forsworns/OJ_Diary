### 1. Two Sum

- 使用一个数组维护快排时发生调换的位置。

- 建哈希表记录读入的数据及位置，注意两个数字相同的情况只有一种，同时map的特性决定了只会插入第一个，第二次用`insert()`时就不会再插入。所以在遍历时第二次出现时再读取第一个在哪里就行。

### 2. Add Two Numbers 

- 链表注意没有head项，所以用自身是否NULL判断循环条件，有head则用next。注意进位。
- 还有一个点是大数加法用链表时采用的反向存储的思路（虽然这里直接给了）

### 3. Longest Substring Without Repeating Characters

- 暴力显然不可取，$O(n^4)$超时
- 类似最长递增子序列思路，选用集合记录当前读取到的字符（C++STL中的set是采用红黑树实现的，unordered_set是哈希实现）
- 直接正反遍历$O(2n)$已经可以消除很多问题，但是例如”ohomm“仍然存在，最后选择了回到重复的字母之后位置。

###  4. Median of Two Sorted Arrays

- 归并的思路
# Code Guide
### #1 Two Sum
#### Difficulty: Easy
#### Date: 2017/5/17
#### Solution
```
1. 保存原序列的副本，再用快排对原序列排序
2. 遍历排序后的序列，对于每个元素a，用target减去a得到另一个数b，然后对a之后的子序列进行二分查找，如果找到b则退出循环
3. 在原序列的副本中找出a和b的索引
```
#### Note
```
1. 注意[3, 2, 3, 1]的情况
2. 用Hash更好
```
[code link](https://github.com/chenup/LeetCode/blob/master/ts1.cpp)
---
### #2 Add Two Numbers
#### Difficulty: Medium
#### Date: 2017/5/17
#### Solution
```
1. 主要是利用L1作为返回链表，先依次遍历L1和L2，将对应的val相加再加上上一个的进位，算出结果val和进位
2. 当其中一个链表遍历到终点时就只需要计算另一个的其余元素就行了，如果没有进位了就可以提前结束了
```
#### Note
```
1. 只能用现有的链表元素拼接不然用局部变量会因为释放而出错
2. 能不计算的地方就不计算不然会超时
```
[code link](https://github.com/chenup/LeetCode/blob/master/atn2.cpp)
---
### #3 Longest Substring Without Repeating Characters
#### Difficulty: Medium
#### Date: 2017/5/19
#### Solution
```
1. 用一个数组保存当前字符串里字符出现的位置，如果没有则为-1
2. 遍历整个字符串，通过cur_l表示当前子字符的长度，max_l表示最大的子字符串的长度,用last表示最新出现的重复字符的位置
```
#### Note
```
1. 重复字符不一定连续，重复字符中间的字符不重复 
```
[code link](https://github.com/chenup/LeetCode/blob/master/lswrc3.cpp)
---
### #4 Median of Two Sorted Arrays
#### Difficulty: Hard
#### Date: 2017/12/16
#### Solution
```
1. 将中位数K分成两部分，A数组一部分，B数组一部分
2. 若A数组中的值小于B数组，则A数组消除那一部分数，K更新为剩下部分的值
3. 继续划分K
4. 若两者相等，则取其一输出返回
5. 若K为1，则取A和B当前最小值进行比对后挑出更小的一个输出
```
#### Note
```
1. 百度的答案，没有考虑到k~~
```
[code link](https://github.com/chenup/LeetCode/blob/master/motsa4.cpp)
---
### #5 Longest Palindromic Substring
#### Difficulty: Medium
#### Date: 2017/8/11
#### Solution
```
1. 遍历字符串，以每个字符为中心判断两种情况：（一）奇数（二）偶数
```
#### Note
```
1. 边界问题
```
[code link](https://github.com/chenup/LeetCode/blob/master/lps5.cpp)
---
### #6 ZigZag Conversion
#### Difficulty: Medium
#### Date: 2017/12/19
#### Solution
```
1. 找规律题
2. 拆分成一个个对勾
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/zzc6.cpp)
---
### #7 Reverse Integer
#### Difficulty: Easy
#### Date: 2017/8/15
#### Solution
```
1. 通过sprintf将整数转化成字符串
2. 反转字符串
3. 用sscanf将字符串转化成整数
```
#### Note
```
1. 注意负数前面的‘-’
2. 边界问题，不能超过32位
```
[code link](https://github.com/chenup/LeetCode/blob/master/ri7.cpp)
---
### #8 String to Integer (atoi)
#### Difficulty: Medium
#### Date: 2017/8/16
#### Solution
```
1. 从字符串里提取有关整数的字符
2. 将字符转化为整数
3. 若超过32位int的边界返回0
```
#### Note
```
1. 注意空格
2. 边界问题
3. “+”和“-”的判断，有些时候正整数没有“+”
```
[code link](https://github.com/chenup/LeetCode/blob/master/sti8.cpp)
---
### #9 Palindrome Number
#### Difficulty: Easy
#### Date: 2017/8/22
#### Solution
```
1. 用sprintf()将整数直接转换为字符串然后判断
```
#### Note
```
1. 负数直接false
```
[code link](https://github.com/chenup/LeetCode/blob/master/pn9.cpp)
---
### #10 Regular Expression Matching
#### Difficulty: Hard
#### Date: 2017/12/25
#### Solution
```
1. 用有向图来表示非确定性状态自动机(NFA)
2. 确定初始状态通过空操作能够到达的集合
3. 遍历这个集合然后获得新的集合
4. 将文本的字符与这个集合中的字符匹配，有则继续，没有则为false
5. 当文本匹配结束后，集合中要包括结束状态才能返回true
```
#### Note
```
1. 这只是一种简化的正则表达式匹配
```
[code link](https://github.com/chenup/LeetCode/blob/master/rem10.cpp)
---
### #11 Container With Most Water
#### Difficulty: Medium
#### Date: 2017/12/19
#### Solution
```
1. 设置两个指针初始时分别指向首部和尾部，计算这两个高度形成的容器的容量，然后选择高度较小的那个指针，往另一个指针靠拢一个位置
2. 重复过程直到两个指针相遇，返回过程中的最大值
```
#### Note
```
1. 暴力求解没有作用，百度大法的
```
[code link](https://github.com/chenup/LeetCode/blob/master/cwmw11.cpp)
---
### #12 Integer to Roman
#### Difficulty: Medium
#### Date: 2017/12/20
#### Solution
```
1.	I = 1;
	V = 5;
	X = 10;
	L = 50;
	C = 100;
	D = 500;
	M = 1000;
2. 每两个阶段的之间有一个减法的表示，比如900=CM， C写在M前面表示M-C，也就是9*10^n和4*10^n的表示
3. 贪心的做法，每次选择能表示的最大值，把对应的字符串连起来。 
4. 例如： 434: CDXXXIV
```
#### Note
```
1. 百度大法好
```
[code link](https://github.com/chenup/LeetCode/blob/master/itr12.cpp)
---
### #13 Roman to Integer 
#### Difficulty: Easy
#### Date: 2017/12/20
#### Solution
```
1. 与12题类似，反向过程
2. 由键取值，一个匹配的过程
3. 事先做好一个map表，然后查表
4. 将key对应的值加到result
```
#### Note
```
1. 对map的使用不熟
```
[code link](https://github.com/chenup/LeetCode/blob/master/rti13.cpp)
---
### #14 Longest Common Prefix
#### Difficulty: Easy
#### Date: 2017/9/4
#### Solution
```
1. 以第一个字符串为主然后和其它字符串进行单个字符匹配，只要不同就退出，直到这个字符串都匹配完
```
#### Note
```
1. 注意当没有字符串存在的情况下应该返回""
```
[code link](https://github.com/chenup/LeetCode/blob/master/lcp14.cpp)
---
### #15 3Sum
#### Difficulty: Medium
#### Date: 2017/12/20
#### Solution
```
1. 用快排排序
2. 先选一个数作为target，从左到右
3. 假设target的索引为i，则使左指针l指向i+1，右指针r指向end
4. 计算是否 target + (*l + *r) == 0, 大于0则移动r, 小于则移动l
5. 去重，指针移动时直接越过相同的数
6. 注意类似于0 0 0的情况，出现在初始状态或者指针移动后的状态
```
#### Note
```
1. 百度大法
2. 属于K SUM问题
3. 还可以使用hashtable来解决，将两个数的组合值作为key，索引对作为value
4. 去重问题
```
[code link](https://github.com/chenup/LeetCode/blob/master/3s15.cpp)
---
### #16 3Sum Closest
#### Difficulty: Medium
#### Date: 2017/9/17
#### Solution
```
1. 先将nums快速排序
2. 使用next记录相同整数的数目
3. 然后从最小的开始遍历，与同样的或次小的数相加后再在之后更大的数中寻找最近似的数
```
#### Note
```
1. 许多小bug
2. 越界
3. 两个负数相加更小
4. 两个正数相加更大
```
[code link](https://github.com/chenup/LeetCode/blob/master/3sc16.cpp)
---
### #17 Letter Combinations of a Phone Number
#### Difficulty: Medium
#### Date: 2017/12/14
#### Solution
```
1. 递归算法
2. 用一个vector保存每个深度的字符，然后等递归返回后再删除
3. 到达最高深度时就将vector保存的字符拼接成字符串保存到结果中
```
#### Note
```
1. 对vector和string的操作不熟悉
2. 对类的概念不熟悉
```
[code link](https://github.com/chenup/LeetCode/blob/master/lcoapn17.cpp)
---
### #18 4Sum
#### Difficulty: Medium
#### Date: 2017/12/21
#### Solution
```
1. 采用hashtable的方法
2. 每两个数的sum构成key，value是一个vector<pair>，每个pair保存数的索引
3. 然后遍历hashtable，每获得一个key1，计算另一个key2 = target - key1，在hashtable中找这个key2是否存在
4. 去重
5. 排序输出
```
#### Note
```
1. K Sum问题
```
[code link](https://github.com/chenup/LeetCode/blob/master/4s18.cpp)
---
### #19 Remove Nth Node From End of List
#### Difficulty: Medium
#### Date: 2017/12/21
#### Solution
```
1. 用三个指针记录访问过的位置
2. 链表拼接
3. 注意删除链表头和n为0的情况
```
#### Note
```
1. 从尾部开始删除
```
[code link](https://github.com/chenup/LeetCode/blob/master/4s18.cpp)
---
### #20 Valid Parentheses
#### Difficulty: Easy
#### Date: 2017/12/10
#### Solution
```
1. 用一个栈存放取出的上半部
2. 遍历字符串，每次遇到上半部就放入栈中，当访问的是下半部再去栈的顶部取符号，比较是否吻合

```
#### Note
```
1. 开辟一个栈即可

```
[code link](https://github.com/chenup/LeetCode/blob/master/vp20.cpp)
---
### #21 Merge Two Sorted Lists
#### Difficulty: Easy
#### Date: 2017/12/10
#### Solution
```
1. 从两个链表中各自取出一个数比较，小的则插入一个返回链表，然后指向下一个，大的不动，等待下次比较
2. 当其中一个链表已经为空，另一个链表剩余部分直接链入返回链表的尾部

```
#### Note
```
1. 不需要另外开辟空间来存链表

```
[code link](https://github.com/chenup/LeetCode/blob/master/mtsl21.cpp)
---
### #22 Generate Parentheses
#### Difficulty: Medium
#### Date: 2017/12/16
#### Solution
```
1. 树结构
2. "("为左结点，")"为右结点
```
#### Note
```
1. 对树的递归结构的理解不足
```
[code link](https://github.com/chenup/LeetCode/blob/master/gp22.cpp)
---
### #23 Merge k Sorted Lists
#### Difficulty: Hard
#### Date: 2017/12/31
#### Solution
```
1. 取k个链表头结点形成k set
2. k set构建AVL，自平衡二叉树
3. 取最小值，然后插入最小值的下一个结点
4. 用map来实现，map底层实现是红黑树
```
#### Note
```
1. 2 sorted是k sorted的一种特例
```
[code link](https://github.com/chenup/LeetCode/blob/master/mksl23.cpp)
---
### #24 Swap Nodes in Pairs
#### Difficulty: Medium
#### Date: 2017/12/11
#### Solution
```
1. 每次交换两个，然后不断迭代
2. 考虑奇数个和偶数个的情况

```
#### Note
```
1. 偶数个结点和奇数个结点的情况，奇数个最后一个不变
```
[code link](https://github.com/chenup/LeetCode/blob/master/snip24.cpp)
---
### #25 Reverse Nodes in k-Group
#### Difficulty: Hard
#### Date: 2017/12/31
#### Solution
```
1. 按照题目思路走，主要是指针的运用
2. 相当于遍历了链表两遍
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/mksl23.cpp)
---
### #26 Remove Duplicates from Sorted Array
#### Difficulty: Easy
#### Date: 2017/12/11
#### Solution
```
1. 因为队列有序，所以只需要判断相邻元素是否相同，如果不同则将长度加一并保存当前的值，相同则删除当前元素然后指向下一个元素
```
#### Note
```
1. 对vector的操作不熟悉，vector.erase(p)删除迭代器p所指定的元素，返回一个指向被删元素之后元素的迭代器
2. 对题目的理解不全面
```
[code link](https://github.com/chenup/LeetCode/blob/master/rdfsa26.cpp)
---
### #27 Remove Element
#### Difficulty: Easy
#### Date: 2017/12/11
#### Solution
```
1. 和26题类似
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/re27.cpp)
---
### #28 Implement strStr()
#### Difficulty: Easy
#### Date: 2017/12/13
#### Solution
```
1. 字符串匹配
2. KMP算法，通过确定状态自动机来匹配，文本字符串指针不回退
3. 暴力求解算法
```
#### Note
```
1. KMP算法没通过，暴力求解算法通过了
```
[code link](https://github.com/chenup/LeetCode/blob/master/is28.cpp)
---
### #29 Divide Two Integers
#### Difficulty: Medium
#### Date: 2018/1/6
#### Solution
```
1. 数值处理问题
2. 以2^n为基进行处理，每次找出最大k满足 m - n * 2^k > 0, res += 2^k, 迭代m, 直到m < n
3. 边界问题，除数为0 或者 被除数是最小负数，除数是-1时，结果越界
```
#### Note
```
1. 百度大法好
```
[code link](https://github.com/chenup/LeetCode/blob/master/dti29.cpp)
---
### #31 Next Permutation
#### Difficulty: Medium
#### Date: 2017/12/13
#### Solution
```
1. 从后往前遍历队列，将最后一个值保存在max中，然后访问往前访问，若下一个数大于等于max则更新max后继续往前，否则得到非最大值的索引并退出当前的循环遍历
2. 将索引+1到队列末尾的数按从小到大排序，因为原先有序则直接收尾替换
3. 在排序后的子队列中寻找与索引指向的数最接近的大值，然后两者替换
```
#### Note
```
1. 子队列排序中首尾替换时的索引容易出错
```
[code link](https://github.com/chenup/LeetCode/blob/master/np31.cpp)
---
### #32 Longest Valid Parentheses
#### Difficulty: Hard
#### Date: 2017/12/31
#### Solution
```
1. 先计算满足匹配条件的‘）’的索引
2. 计算后一个索引离前一个索引的距离
3. 有1，2和大于2的情况
4. 从后往前遍历，若为1和2则保持，如果大于2，则比较该数与1的总数+2的大小，若小于等于则说明还有更长的匹配串，否则计算新的匹配串
5. 保存当中的最大值
6. 返回最大值乘2
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/lvp32.cpp)
---
### #33 Search in Rotated Sorted Array
#### Difficulty: Medium
#### Date: 2017/12/23
#### Solution
```
1. 先遍历，找到右值比左值小的点再二分法
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/sirsa33.cpp)
---
### #34 Search for a Range
#### Difficulty: Medium
#### Date: 2017/12/21
#### Solution
```
1. 二分查找
2. 根据返回的索引的前后值是否相同来确定范围
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/sfar34.cpp)
---
### #35 Search Insert Position
#### Difficulty: Easy
#### Date: 2017/12/12
#### Solution
```
1. 遍历vector，找到第一个比target大的位置即可
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/sip35.cpp)
---
### #36 Valid Sudoku
#### Difficulty: Medium
#### Date: 2017/12/31
#### Solution
```
1. 时间换空间，遍历矩阵三次
2. 空间换时间，遍历矩阵一次，但是用三个矩阵来记录结果，分别对应行、列和小矩阵
3. 每行不能重复
4. 每列不能重复
5. 每个小矩阵不能重复
```
#### Note
```
1. 没跑出来
2. 百度大法
3. vector<vector<char>> 出错
```
[code link](https://github.com/chenup/LeetCode/blob/master/vs36.cpp)
---
### #38 Count and Say
#### Difficulty: Easy
#### Date: 2018/1/6
#### Solution
```
1. 后一个字符串是从前一个字符串推出来的
2. 要得到第n个字符串就要先获得前n-1个
3. 用count值记录连续的相同值
```
#### Note
```
1. 百度大法
```
[code link](https://github.com/chenup/LeetCode/blob/master/cas38.cpp)
---
### #39 Combination Sum
#### Difficulty: Medium
#### Date: 2017/12/22
#### Solution
```
1. 先快排输入的数组
2. 用二分法得到小于等于target的最近位置end
3. 通过递归找到所有满足和为target的元素，范围在0到end
```
#### Note
```
1. 注意别逆向输出
```
[code link](https://github.com/chenup/LeetCode/blob/master/cs39.cpp)
---
### #40 Combination Sum II
#### Difficulty: Medium
#### Date: 2017/12/23
#### Solution
```
1. 类似39题
2. 递归过程中去重
3. 用set去重
```
#### Note
```
1. 二分法使用有误
2. 递归过程中return换成continue
```
[code link](https://github.com/chenup/LeetCode/blob/master/csII40.cpp)
---
### #43 Multiply Strings
#### Difficulty: Medium
#### Date: 2017/12/23
#### Solution
```
1. 乘法变加法
2. 分段相加
3. 用vector<int>保存临时结果，最后转化成string
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/ms43.cpp)
---
### #46 Permutations
#### Difficulty: Medium
#### Date: 2017/12/14
#### Solution
```
1. 递归方法
2. 遍历队列，先取出一个值放入临时vector，然后到一个深度重新遍历剩余的变量，重复操作，等返回时再将临时vector中的值取出，放入到队列原先的位置
3. 到达最深处队列为空时，将临时vector保存到结果中
```
#### Note
```
1. 对于vector的迭代指针操作、vector的插入和删除操作不是很熟悉
```
[code link](https://github.com/chenup/LeetCode/blob/master/p46.cpp)
---
### #47 Permutations II
#### Difficulty: Medium
#### Date: 2017/12/21
#### Solution
```
1. 基本思路和46题一样
2. 先将输入数组快排
3. 每次取数时先判断在它之前值相等的数是否取出，没有就不取，这是去重操作
```
#### Note
```
1. 百度大法
```
[code link](https://github.com/chenup/LeetCode/blob/master/pII47.cpp)
---
### #48 Rotate Image
#### Difficulty: Medium
#### Date: 2017/12/24
#### Solution
```
1. 将i行的每列元素依次插入到每行的倒数第i列
2. 删除i行的前n个元素
```
#### Note
```
1. 对插入和删除操作不熟悉
```
[code link](https://github.com/chenup/LeetCode/blob/master/ri48.cpp)
---
### #49 Group Anagrams
#### Difficulty: Medium
#### Date: 2017/12/24
#### Solution
```
1. 把错位词的字符顺序重新排列，那么会得到相同的结果，所以重新排序是判断是否互为错位词的方法
2. 由于错位词重新排序后都会得到相同的字符串，我们以此作为key，将所有错位词都保存到字符串数组中，建立key和字符串数组之间的映射
3. 最后再存入结果res中即可
```
#### Note
```
1. 百度大法
2. sort可以对string排序
3. map中key自动排序
4. 用一个大小为26的int数组来统计每个单词中字符出现的次数，然后将int数组转为一个唯一的字符串，跟字符串数组进行映射，这样我们就不用给字符串排序了
5. 用hash表，但是可能有误，毕竟hash值可能相同，值不同
6. 对于c++的使用不熟，很简单的程序写了很久
7. 案例给的不清楚
```
[code link](https://github.com/chenup/LeetCode/blob/master/ga49.cpp)
---
### #50 Pow(x, n)
#### Difficulty: Medium
#### Date: 2017/12/24
#### Solution
```
1. 递归
2. n为偶数则，pow(x, n / 2) * pow(x, n / 2)
3. n为奇数则，pow(x, n / 2) * pow(x, n / 2) * x
4. n为0时，返回1
```
#### Note
```
1. x可能为0，n可能为负，n也可能为0
```
[code link](https://github.com/chenup/LeetCode/blob/master/p50.cpp)
---
### #53 Maximum Subarray
#### Difficulty: Easy
#### Date: 2017/12/10
#### Solution
```
1. 遍历数组，保存一个全局最大值和局部最大值，在遍历的过程中将整数相加，若和小于当前整数，说明前面数的和为负数可以放弃，以当前的数重新开始寻找，但是要保存上一个序列的最大值
2. 用局部最大值更新全局最大值
```
#### Note
```
1. 不知道这是不是动态规划的题，通过划分子问题的方法来求解？
```
[code link](https://github.com/chenup/LeetCode/blob/master/ms53.cpp)
---
### #54 Spiral Matrix
#### Difficulty: Medium
#### Date: 2017/12/17
#### Solution
```
1. 按照顺时针方式遍历二维数组，一共有四个方向，右、下、左、上
```
#### Note
```
1. 注意边界
```
[code link](https://github.com/chenup/LeetCode/blob/master/sm54.cpp)
---
### #55 Jump Game
#### Difficulty: Medium
#### Date: 2017/12/24
#### Solution
```
1. 可以用贪心法和动态规划（递归）
2. 最好的是贪心法，从右往左，要到达最右边，先要到达次右边，以此类推，最后看发出点是否为0，为0则为true，currPosition + nums[currPosition] >= leftmostGoodIndex
```
#### Note
```
1. 试错了很多次
2. leetcode上提供了4种解法
```
[code link](https://github.com/chenup/LeetCode/blob/master/jg55.cpp)
---
### #56 Merge Intervals
#### Difficulty: Medium
#### Date: 2017/12/25
#### Solution
```
1. 先以interval.start为主对intervals排序
2. 如果it.end < (it+1).start时则移动到下一个元素
3. 否则看是否it.end < (it+1).end，如果是则进行更新
4. 删除(it+1)，重复上述过程
```
#### Note
```
1. leetcode上提供了解法
2. 对sort(s,e,cmp)的cmp的用法不熟
```
[code link](https://github.com/chenup/LeetCode/blob/master/mi56.cpp)
---
### #58 Length of Last Word
#### Difficulty: Easy
#### Date: 2017/12/13
#### Solution
```
1. 从字符串的后面往前遍历遇到第一个空格结束
```
#### Note
```
1. 最后一个单词后面可能有许多空格，这个要略过
```
[code link](https://github.com/chenup/LeetCode/blob/master/lolw58.cpp)
---
### #59 Spiral Matrix II
#### Difficulty: Medium
#### Date: 2017/12/18
#### Solution
```
1. 类似54题，遍历过程中填数
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/smII59.cpp)
---
### #60 Permutation Sequence
#### Difficulty: Medium
#### Date: 2017/12/25
#### Solution
```
1. 直接根据k来计算每次应该访问第几个元素,然后将该元素从队列删除
2. 递归法
3. k / n!
4. k % n!
```
#### Note
```
1. k应该从0开始计算，而不是1，否则/和%运算会出错
```
[code link](https://github.com/chenup/LeetCode/blob/master/ps60.cpp)
---
### #61 Rotate List
#### Difficulty: Medium
#### Date: 2017/12/17
#### Solution
```
1. 将右边的k个结点平移到链表首
2. 先计算链表的长度l
3. 再找到第l-k+1个结点的地址作为结果返回
4. 将两部分链接起来
```
#### Note
```
1. 左移和右移混淆
```
[code link](https://github.com/chenup/LeetCode/blob/master/rl61.cpp)
---
### #62 Unique Paths
#### Difficulty: Medium
#### Date: 2017/12/26
#### Solution
```
1. 动态规划
2. 用空间换时间，通过(m + 1) * (n + 1)的数组记录步数，不知道是否还可以只记录最近的步数节省空间
3. f(m, n) = f(m - 1, n) + f(m, n - 1)，如果表中已经存在则直接使用，没有则在计算后填入表中
4. 初始状态如f(0, 0), f(1, 1), f(1, 2), f(1, 0), f(0, 1)这些
```
#### Note
```
1. 对子问题的划分有问题
```
[code link](https://github.com/chenup/LeetCode/blob/master/up62.cpp)
---
### #63 Unique Paths II
#### Difficulty: Medium
#### Date: 2017/12/26
#### Solution
```
1. 和62题类似
2. 当遇到障碍物时，将该点的路径数设为0
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/up63.cpp)
---
### #64 Minimum Path Sum
#### Difficulty: Medium
#### Date: 2017/12/26
#### Solution
```
1. 和62题类似
2. f(m, n) = min(f(m, n - 1), f(m - 1, n)) + a[m][n]
3. f(0, n) = f(0, n - 1) + a[0][n]
4. f(m, 0) = f(m - 1, 0) + a[m][0]
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/mps64.cpp)
---
### #66 Plus One
#### Difficulty: Medium
#### Date: 2018/1/7
#### Solution
```
1. 将一个非负整数+1后用vector来表示
```
#### Note
```
1. 百度大法好
2. 其实很简单
```
[code link](https://github.com/chenup/LeetCode/blob/master/po66.cpp)
---
### #67 Add Binary
#### Difficulty: Easy
#### Date: 2017/12/17
#### Solution
```
1. 从后往前遍历两个string，将两个string对应的数值相加再加上进位，将得到的结果插入到结果的首部，并计算下个进位的值
2. 结果字符串的长度为 max(a.size(), b.size()) + c, c为最后的进位值
```
#### Note
```
1. 0x10 和0x02混淆

```
[code link](https://github.com/chenup/LeetCode/blob/master/ab67.cpp)
---
### #69 Sqrt(x)
#### Difficulty: Easy
#### Date: 2018/1/7
#### Solution
```
1. 二分法，和二分查找类似
2. m * m <= x < (m + 1) * (m + 1)
3. 将乘法变为除法，否则会溢出
```
#### Note
```
1. 百度大法好
2. 第二种方法是牛顿法
3. y_(n+1) = y_n - f(y_n) / f'(y_n) = (y_n + x / y_n) / 2
4. f(y) = y^2 - x
5. f(y) = 0
```
[code link](https://github.com/chenup/LeetCode/blob/master/s69.cpp)
---
### #70 Climbing Stairs
#### Difficulty: Easy
#### Date: 2017/12/18
#### Solution
```
1. 动态规划
2. f(n) = f(n-1) + f(n-2)，爬第n级的台阶等于从第n-1级台阶跨1步和从第n-2级台阶跨2步
```
#### Note
```
1. f(0)=0, f(1)=1, f(2)=2
```
[code link](https://github.com/chenup/LeetCode/blob/master/cs70.cpp)
---
### #71 Simplify Path
#### Difficulty: Medium
#### Date: 2017/12/27
#### Solution
```
1. 用一个vector存储目录，不存"/"
2. 当path[i] == "/"时，如果之前str为"..",则pop; 如果为".",则什么都不做; 如果非空则push
3. 还要考虑string尾部不是"/"时，也要对剩下的str进行操作
```
#### Note
```
1. 需要记规则
```
[code link](https://github.com/chenup/LeetCode/blob/master/sp71.cpp)
---
### #73 Set Matrix Zeroes
#### Difficulty: Medium
#### Date: 2017/12/27
#### Solution
```
1. 遍历矩阵里的所有元素，把为0元素的行和列分别保存在两个set中
2. 遍历行set，把对应的行的元素都设为0
3. 遍历列set，把对应的列的元素都设为0
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/smz73.cpp)
---
### #74 Search a 2D Matrix
#### Difficulty: Medium
#### Date: 2017/12/27
#### Solution
```
1. 二分法
2. 将k转化成i和j
3. i = k / n
4. j = k % n
```
#### Note
```
1. 注意矩阵为空的情况
```
[code link](https://github.com/chenup/LeetCode/blob/master/sa2m74.cpp)
---
### #75 Sort Colors
#### Difficulty: Medium
#### Date: 2017/12/27
#### Solution
```
1. 0插入到队首，3插入到队尾，1不变
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/sc75.cpp)
---
### #77 Combinations
#### Difficulty: Medium
#### Date: 2017/12/27
#### Solution
```
1. 递归
2. 每次遍历i到n - k + 1
3. 到k为0为止
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/c77.cpp)
---
### #78 Subsets
#### Difficulty: Medium
#### Date: 2017/12/27
#### Solution
```
1. 递归
2. 每次遍历从i到n
3. 每个中间过程保存到结果
4. i超过n结束
5. 空集要加到结果中
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/s78.cpp)
---
### #79 Word Search
#### Difficulty: Medium
#### Date: 2017/12/28
#### Solution
```
1. 递归
2. 有left、up、right和down四种走法
3. 匹配
```
#### Note
```
1. leetcode用例感觉有问题
2. 没通过
3. 思路是对的，但是别人的用例能过
```
[code link](https://github.com/chenup/LeetCode/blob/master/ws79.cpp)
---
### #80 Remove Duplicates from Sorted Array II
#### Difficulty: Medium
#### Date: 2017/12/29
#### Solution
```
1. 与第26题类似
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/rdfsaII80.cpp)
---
### #81 Search in Rotated Sorted Array II
#### Difficulty: Medium
#### Date: 2017/12/29
#### Solution
```
1. 与第33题类似
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/sirsaII81.cpp)
---
### #82 Remove Duplicates from Sorted List II
#### Difficulty: Medium
#### Date: 2017/12/29
#### Solution
```
1. 遍历链表，找出一段相同值的头的前置结点和尾结点
2. 考虑原head的值被清除的情况
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/rdfslII82.cpp)
---
### #83 Remove Duplicates from Sorted List
#### Difficulty: Medium
#### Date: 2017/12/29
#### Solution
```
1. 和82题类似
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/rdfsl83.cpp)
---
### #86 Partition List
#### Difficulty: Medium
#### Date: 2018/1/2
#### Solution
```
1. 指针的运用
2. 通过几个指针在遍历链表的过程中完成分区
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/pl86.cpp)
---
### #88 Merge Sorted Array
#### Difficulty: Easy
#### Date: 2018/1/2
#### Solution
```
1. 毕竟两个队列元素的大小，如果第二个队列里更小的就插入到第一个里面
```
#### Note
```
1. 清除第一个队列里多余的元素
```
[code link](https://github.com/chenup/LeetCode/blob/master/msa88.cpp)
---
### #89 Gray Code
#### Difficulty: Medium
#### Date: 2018/1/2
#### Solution
```
1. 格雷码是一种模型题，如果知道规律很好解答
2. 通过递归方法解答的没做对
3. 比较好的还有镜像方法
4. 遍历0 ~ 2^n - 1 ,其中 格雷码为 i ^ (i >> 1)
```
#### Note
```
1. 百度大法好
2. 4种方法
```
[code link](https://github.com/chenup/LeetCode/blob/master/gc89.cpp)
---
### #90 Subsets II
#### Difficulty: Medium
#### Date: 2018/1/2
#### Solution
```
1. 快排
2. 递归
3. 去重
```
#### Note
``` 
```
[code link](https://github.com/chenup/LeetCode/blob/master/sII90.cpp)
---
### #91 Decode Ways
#### Difficulty: Medium
#### Date: 2018/1/2
#### Solution
```
1. 动态规划
2. f3 = f2 * judage2 + f1 * judge1
3. 注意0的情况
```
#### Note
``` 
```
[code link](https://github.com/chenup/LeetCode/blob/master/dw91.cpp)
---
### #92 Reverse Linked List II
#### Difficulty: Medium
#### Date: 2018/1/2
#### Solution
```
1. 指针的运用
2. 遍历一遍链表
```
#### Note
``` 
```
[code link](https://github.com/chenup/LeetCode/blob/master/rllII92.cpp)
---
### #93 Restore IP Addresses
#### Difficulty: Medium
#### Date: 2018/1/3
#### Solution
```
1. 递归
```
#### Note
```
1. 注意0的情况
```
[code link](https://github.com/chenup/LeetCode/blob/master/ria93.cpp)
---
### #94 Binary Tree Inorder Traversal 
#### Difficulty: Medium
#### Date: 2018/1/3
#### Solution
```
1. 用栈实现
2. 记录当前结点是否被访问
```
#### Note
```
1. 中序遍历： 左根右
2. 先序遍历： 根左右
3. 后序遍历： 左右根
4. 更好的方法可以不用visit
```
[code link](https://github.com/chenup/LeetCode/blob/master/btit94.cpp)
---
### #95 Unique Binary Search Trees II
#### Difficulty: Medium
#### Date: 2018/1/6
#### Solution
```
1. 与96题类似
2. 递归
3. 动态分配内存
4. 选取一个点，然后对左子树和右子树进行操作
```
#### Note
```
1. 百度大法好
2. new 动态为变量分配内存，返回内存地址
```
[code link](https://github.com/chenup/LeetCode/blob/master/ubstII95.cpp)
---
### #96 Unique Binary Search Trees
#### Difficulty: Medium
#### Date: 2018/1/6
#### Solution
```
1. 令h(0)=1，h(1)=1，Catalan数满足递归式：h(n) = h(0)*h(n-1) + h(1)*h(n-2) + ... + h(n-1)*h(0)  (n>=2)
2. 该递推关系的解为：h(n) = C(2n,n)/(n+1)，n=0,1,2,3,... （其中C(2n,n)表示2n个物品中取n个的组合数
3. 动态规划
4. 从处理子问题的角度来看，选取一个结点为根，就把结点切成左右子树，以这个结点为根的可行二叉树数量就是左右子树可行二叉树数量的乘积，所以总的数量是将以所有结点为根的可行结果累加起来。
```
#### Note
```
1. 百度大法好
2. 用组合数会溢出
```
[code link](https://github.com/chenup/LeetCode/blob/master/ubst96.cpp)
---
### #98 Validate Binary Search Tree
#### Difficulty: Medium
#### Date: 2018/1/8
#### Solution
```
1. 中序遍历
2. 递归
3. 中序遍历的结果是后一个元素都比前一个元素大
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/vbst98.cpp)
---
### #100 Same Tree
#### Difficulty: Easy
#### Date: 2018/1/8
#### Solution
```
1. 先序遍历
2. 递归
3. 比较对应结点
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/st100.cpp)
---
### #101 Symmetric Tree
#### Difficulty: Easy
#### Date: 2018/1/24
#### Solution
```
1. 判断root是否为空，为空则返回真
2. 如果root不为空，则比较左子树和右子树的根的值是否相等
3. 然后在判断左根的左子树和右根的右子树，左根的右子树和右根的左子树
```
#### Note
```
1. 用了100题的方法
```
[code link](https://github.com/chenup/LeetCode/blob/master/st101.cpp)
---
### #102 Binary Tree Level Order Traversal
#### Difficulty: Medium
#### Date: 2018/1/24
#### Solution
```
1. 层次遍历
2. 保存最近一层的最后一个结点的索引
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/btlot102.cpp)
---
### #103 Binary Tree Zigzag Level Order Traversal
#### Difficulty: Medium
#### Date: 2018/1/24
#### Solution
```
1. 类似于第102题
2. 遇到偶数层则逆序输出
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/btzlot103.cpp)
---
### #104 Maximum Depth of Binary Tree
#### Difficulty: Easy
#### Date: 2018/1/25
#### Solution
```
1. 层次遍历
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/mdobt104.cpp)
---
### #105 Construct Binary Tree from Preorder and Inorder Traversal
#### Difficulty: Medium
#### Date: 2018/1/29
#### Solution
```
1. 递归
2. 根据先序序列的首部，将中序序列划分左子树和右子树
3. 然后根据左子树和右子树的数目划分先序序列
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/cbtfpait105.cpp)
---
### #106 Construct Binary Tree from Inorder and Postorder Traversal
#### Difficulty: Medium
#### Date: 2018/1/29
#### Solution
```
1. 递归
2. 根据后序序列的尾部，将中序序列划分左子树和右子树
3. 然后根据左子树和右子树的数目划分后序序列
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/cbtfiapt106.cpp)
---
### #107 Binary Tree Level Order Traversal II
#### Difficulty: Easy
#### Date: 2018/1/25
#### Solution
```
1. 层次遍历
2. reverse(begin, end)逆序
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/btlotII107.cpp)
---
### #108 Convert Sorted Array to Binary Search Tree
#### Difficulty: Easy
#### Date: 2018/1/28
#### Solution
```
1. 取有序序列的中间值作为根，左半部作为左子树，右半部作为右子树
2. 递归
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/csatbst108.cpp)
---
### #109 Convert Sorted List to Binary Search Tree
#### Difficulty: Medium
#### Date: 2018/1/28
#### Solution
```
1. 中序遍历对应有序数组
2. 取有序序列的中间值作为根，左半部作为左子树，右半部作为右子树
3. 递归
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/csltbst109.cpp)
---
### #110 Balanced Binary Tree
#### Difficulty: Easy
#### Date: 2018/1/27
#### Solution
```
1. 递归
2. pair<bool, int>, 第一个判断子树是否balanced，第二个保存子树的高度
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/bbt110.cpp)
---
### #111 Minimum Depth of Binary Tree
#### Difficulty: Easy
#### Date: 2018/1/27
#### Solution
```
1. 层次遍历
2. 返回遇到的第一个叶子结点的深度
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/mdobt111.cpp)
---
### #112 Path Sum
#### Difficulty: Easy
#### Date: 2018/1/27
#### Solution
```
1. 深度遍历
2. 途中记录总的路径数
3. 递归
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/ps112.cpp)
---
### #113 Path Sum II
#### Difficulty: Medium
#### Date: 2018/1/27
#### Solution
```
1. 和112题类似
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/psII113.cpp)
---
### #114 Flatten Binary Tree to Linked List
#### Difficulty: Medium
#### Date: 2018/1/27
#### Solution
```
1. 先序遍历
2. 递归方法
```
#### Note
```
1. 百度大法好
2. 有递归和非递归
```
[code link](https://github.com/chenup/LeetCode/blob/master/fbttll114.cpp)
---
### #116 Populating Next Right Pointers in Each Node
#### Difficulty: Medium
#### Date: 2018/1/27
#### Solution
```
1. 层次遍历
2. 每层通过next来遍历
3. 本身是完全二叉树
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/pnrpien116.cpp)
---
### #117 Populating Next Right Pointers in Each Node II
#### Difficulty: Medium
#### Date: 2018/1/27
#### Solution
```
1. 和116题类似
3. 任意二叉树
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/pnrpienII117.cpp)
---
### #118 Pascal's Triangle
#### Difficulty: Easy
#### Date: 2017/12/19
#### Solution
```
1. 按照Pascal's triangle的思路走就行了，层层推进
```
#### Note
```
1. 注意边界
```
[code link](https://github.com/chenup/LeetCode/blob/master/pt118.cpp)
---
### #119 Pascal's Triangle II
#### Difficulty: Easy
#### Date: 2017/12/19
#### Solution
```
1. 类似118题
2. 只能使用一个vector<int>保存上一层数值
```
#### Note
```
1. 注意边界
2. 注意空间复杂度
```
[code link](https://github.com/chenup/LeetCode/blob/master/ptII119.cpp)
---
### #120 Triangle
#### Difficulty: Medium
#### Date: 2017/12/19
#### Solution
```
1. 自底向上层层更新，每层的每个数值代表从最底部到它的最短路径值
2. 最终根元素代表整个结构的最短路径值
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/t120.cpp)
---
### #121 Best Time to Buy and Sell Stock
#### Difficulty: Easy
#### Date: 2018/1/28
#### Solution
```
1. 遍历数组
2. 设置第一个元素为buy和sell
3. 若当前元素小于buy，则计算sell - buy，保存最大profit，将新的元素设置为buy和sell
4. 若当前元素大于sell，则设置新的sell
5. 最后计算sell - buy，取最大profit
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/bttbass121.cpp)
---
### #122 Best Time to Buy and Sell Stock II
#### Difficulty: Easy
#### Date: 2018/1/28
#### Solution
```
1. 把所有小到大的区间的值相加
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/bttbassII122.cpp)
---
### #125 Valid Palindrome
#### Difficulty: Easy
#### Date: 2018/1/28
#### Solution
```
1. 回文判断方法
2. 只保留数字和字母
3. 边界问题
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/vp125.cpp)
---
### #127 Word Ladder
#### Difficulty: Medium
#### Date: 2018/2/2
#### Solution
```
1. visit数组保存当前要访问的字符串，next数组保存与visit相差一个字母的字符串
2. 初始将beginWord放入visit
3. 每次将字符串放入next数组后就删除原wordList里的相同字符串
4. 当next为空则返回0
5. 当endWord存在于next时就返回当前深度
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/wl127.cpp)
---
### #129 Sum Root to Leaf Numbers
#### Difficulty: Medium
#### Date: 2018/1/29
#### Solution
```
1. 深度遍历
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/srtln129.cpp)
---
### #130 Surrounded Regions
#### Difficulty: Medium
#### Date: 2018/1/29
#### Solution
```
1. 访问外围一圈的元素，如果是O的话则递归访问它的相邻元素，并将状态设为visited
2. 最后将未访问的O设置为X
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/sr130.cpp)
---
### #131 Palindrome Partitioning
#### Difficulty: Medium
#### Date: 2018/2/2
#### Solution
```
1. 递归
2. 假设将字符串 s 分割为两段，[0,i-1], [i, n-1]，如果[0, i-1] 为回文字符串，[i, n-1]为回文字符串集合，那么 s 就是一个有效字符串。将 i 从 1 到 n-1遍历一次，求得所有满足条件的集合
```
#### Note
```
1. 子问题重复求解，可以保存之前求得的子回文字符串集合
2. 空间换时间
```
[code link](https://github.com/chenup/LeetCode/blob/master/pp131.cpp)
---
### #133 Clone Graph
#### Difficulty: Medium
#### Date: 2018/1/30
#### Solution
```
1. 图的广度优先遍历
2. 通过visited和clone_visited来建立原点和copy点的映射
```
#### Note
```
1. 通过Hashmap来建立映射更方便，原点为key，copy为值
2. 也可以使用图的深度优先遍历
```
[code link](https://github.com/chenup/LeetCode/blob/master/cg133.cpp)
---
### #136 Single Number
#### Difficulty: Easy
#### Date: 2018/1/29
#### Solution
```
1. 快排
```
#### Note
```
1. 所有元素异或
2. hash表
```
[code link](https://github.com/chenup/LeetCode/blob/master/sn136.cpp)
---
### #137 Single Number II
#### Difficulty: Medium
#### Date: 2018/1/29
#### Solution
```
1. 快排
```
#### Note
```
1. hash表
2. (3 * sum(set(nums)) - sum(nums)) / 2
```
[code link](https://github.com/chenup/LeetCode/blob/master/snII137.cpp)
---
### #138 Copy List with Random Pointer
#### Difficulty: Medium
#### Date: 2018/2/1
#### Solution
```
1. 建立哈希映射表，将node和copy node一一映射
2. 遍历链表途中建立新的链表
```
#### Note
```
1. 提交代码时可以使用map但是不能使用hash_map
2. map的底层实现是红黑树，hash_map的底层实现是哈希表
```
[code link](https://github.com/chenup/LeetCode/blob/master/clwrp138.cpp)
---
### #139 Word Break
#### Difficulty: Medium
#### Date: 2018/2/2
#### Solution
```
1. 利用unordered_set查询比三向单词查找树快，而且 unordered_set是c++自带的数据结构
2. 假设将字符串 s 分割为两段，[0,i-1], [i, n-1]，如果[0, i-1] 为有效单词，[i, n-1]为有效单词集合，那么 s 就是一个有效字符串。将 i 从 1 到 n-1遍历一次，求得s是否是一个有效字符串
3. 利用DP思路，即表格法，记录已计算结果，这样出现很多反复求解的子问题时在常数时间就可以解决，效率高
4. 递归，划分子问题
```
#### Note
```
1. 百度大法好
2. set的底层实现是红黑树，unordered_set的底层实现是hash表
3. 用三向单词查找树出现超时，而且对反复求解的子问题没有记录
```
[code link](https://github.com/chenup/LeetCode/blob/master/wb139.cpp)
---
### #141 Linked List Cycle
#### Difficulty: Easy
#### Date: 2018/2/2
#### Solution
```
1. 通过hash表比用vector效率要高，插入和查找的效率都快，vector的底层实现是红黑树
2. 如果访问到null则返回false
3. 将已访问到的结点保存到hash表里，若当前访问的结点已存在hash表则返回true
```
#### Note
```
1. 若是没有额外空间消耗，则通过快指针和慢指针赛跑，如果快指针追上慢指针则代表有循环
```
[code link](https://github.com/chenup/LeetCode/blob/master/llc141.cpp)
---
### #142 Linked List Cycle II
#### Difficulty: Medium
#### Date: 2018/2/18
#### Solution
```
1. 通过hash表比用vector效率要高，插入和查找的效率都快，vector的底层实现是红黑树
2. 如果访问到null则返回null
3. 将已访问到的结点保存到hash表里，若当前访问的结点已存在hash表则返回当前结点
```
#### Note
```
1. 百度大法好
2. 设置一个快指针fp和一个慢指针sp，两个指针起始同时指向head节点，其中快指针每次走两步，慢指针每次走一步 
3. 如果链表中存在环，那么fp和sp一定会相遇，当两个指针相遇的时候，我们设相遇点为c，此时fp和sp都指向了c，接下来令fp继续指向c结点，sp指向链表头结点head，此时最大的不同是fp的步数变成为每次走一步，令fp和sp同时走，每次一步，那么它们再次相遇的时候即为环的入口结点
```
[code link](https://github.com/chenup/LeetCode/blob/master/llcII142.cpp)
---
### #143 Reorder List
#### Difficulty: Medium
#### Date: 2018/2/18
#### Solution
```
1. 通过快指针和慢指针将链表一分为二
2. 快指针每次加2，慢指针每次加1
3. 将后半部分进行reverse操作
4. 合并两部分
```
#### Note
```
1. 百度大法好
```
[code link](https://github.com/chenup/LeetCode/blob/master/rl143.cpp)
---


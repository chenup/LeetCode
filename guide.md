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
[code link](https://github.com/chenup/LeetCode/blob/master/code/ts1.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/atn2.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/lswrc3.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/motsa4.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/lps5.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/zzc6.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/ri7.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/sti8.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/pn9.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/rem10.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/cwmw11.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/itr12.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/rti13.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/lcp14.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/3s15.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/3sc16.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/lcoapn17.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/4s18.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/4s18.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/vp20.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/mtsl21.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/gp22.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/mksl23.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/snip24.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/mksl23.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/rdfsa26.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/re27.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/is28.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/dti29.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/np31.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/lvp32.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/sirsa33.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/sfar34.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/sip35.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/vs36.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/cas38.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/cs39.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/csII40.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/ms43.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/p46.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/pII47.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/ri48.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/ga49.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/p50.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/ms53.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/sm54.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/jg55.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/mi56.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/lolw58.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/smII59.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/ps60.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/rl61.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/up62.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/up63.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/mps64.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/po66.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/ab67.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/s69.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/cs70.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/sp71.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/smz73.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/sa2m74.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/sc75.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/c77.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/s78.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/ws79.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/rdfsaII80.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/sirsaII81.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/rdfslII82.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/rdfsl83.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/pl86.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/msa88.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/gc89.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/sII90.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/dw91.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/rllII92.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/ria93.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/btit94.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/ubstII95.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/ubst96.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/vbst98.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/st100.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/st101.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/btlot102.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/btzlot103.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/mdobt104.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/cbtfpait105.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/cbtfiapt106.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/btlotII107.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/csatbst108.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/csltbst109.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/bbt110.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/mdobt111.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/ps112.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/psII113.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/fbttll114.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/pnrpien116.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/pnrpienII117.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/pt118.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/ptII119.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/t120.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/bttbass121.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/bttbassII122.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/vp125.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/wl127.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/srtln129.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/sr130.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/pp131.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/cg133.cpp)
---
### #134 Gas Station
#### Difficulty: Medium
#### Date: 2018/2/20
#### Solution
```
1. 先计算gas[i] - cost[i]
2. 从0到size - 1遍历数组，将所有值相加得total
3. 初始时sum为0，如果sum小于0则从下一个点开始计算，并记录开始点，sum归0，否则sum加上当前值
3. 最后判断total是否小于0，若小于0则返回-1，否则返回记录点
```
#### Note
```
1. 百度大法好
2. 想的太复杂
3. 后面不行前面肯定不行，所以不需要回溯
4. 当到达末尾时sum大于0，并且total大于0就说明可以继续走到记录点，因为就算记录点之前的值为负，sum也可以抵消它
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/gs134.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/sn136.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/snII137.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/clwrp138.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/wb139.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/llc141.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/llcII142.cpp)
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
[code link](https://github.com/chenup/LeetCode/blob/master/code/rl143.cpp)
---
### #144 Binary Tree Preorder Traversal
#### Difficulty: Medium
#### Date: 2018/2/19
#### Solution
```
1. 通过栈实现迭代方式
2. 先序: 先根再左再右
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/btpt144.cpp)
---
### #145 Binary Tree Postorder Traversal
#### Difficulty: Hard
#### Date: 2018/2/19
#### Solution
```
1. 通过栈实现迭代方式
2. 通过visited来判断结点有没有之前被访问过
3. 后序: 先左再右再根
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/btpt145.cpp)
---
### #147 Insertion Sort List
#### Difficulty: Medium
#### Date: 2018/2/19
#### Solution
```
1. 插入排序
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/isl147.cpp)
---
### #148 Sort List
#### Difficulty: Medium
#### Date: 2018/2/20
#### Solution
```
1. 符合 O(nlgn)要求只有快速排序，归并排序，堆排序
2. 而根据单链表的特点，最适于用归并排序
3. 快排也行
4. 递归
5. 归并排序是分治法，取中点，划分左集合和右集合，然后合并
6. 快排取一个key，然后划分小于和大于等于它的
```
#### Note
```
1. 百度大法好
2. 快排没通过，但是本机测试正确
3. 归并排序通过了
4. 归并排序的实现更简单
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/sl148.cpp)
---
### #150 Evaluate Reverse Polish Notation
#### Difficulty: Medium
#### Date: 2018/2/20
#### Solution
```
1. 后缀表达式用栈来实现
```
#### Note
```
1. 有负数和超过个位的整数
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/erpn150.cpp)
---
### #151 Reverse Words in a String
#### Difficulty: Medium
#### Date: 2018/2/21
#### Solution
```
1. 去除单词间重复的空格，注意首尾空格
2. 可以先将空格去除和单词翻转，最后将整个字符串翻转
3. 也可以通过输入流来将后一个字符串插入到前一个字符串
```
#### Note
```
1. 百度大法好
2. 简单问题想复杂，事先应该先设计再编码，太急了
3. 没有活用c++的知识
4. reserve和resize函数
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/rwias151.cpp)
---
### #152 Maximum Product Subarray
#### Difficulty: Medium
#### Date: 2018/2/22
#### Solution
```
1. 遍历数组
2. 每遇到一个0值都是一个重新计算的过程，但是要保留之前的最大值
2. 若值为正，则乘到之前的乘积上，并更新最大值
3. 若值为负，若之前的负数累计数为0, 则记录之前的乘积和该负数，更新累计数；若累计数为偶数，则用当前乘积乘上该负数，除掉第一个负数和它之前的乘积，更新乘积和累计数和最大值；若累计为奇数，则用当前乘积乘上该负数，并更新乘积和最大值和累计数
4. 返回最大值
```
#### Note
``` 
1. 若数组数目为1，则直接返回该数
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/mps152.cpp)
---
### #153 Find Minimum in Rotated Sorted Array
#### Difficulty: Medium
#### Date: 2018/2/21
#### Solution
```
1. 遍历数组， 比较当前数和下一个数，若当前数大于下一个数，那最小值就是下一个数，结束
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/fmirsa153.cpp)
---
### #154 Find Minimum in Rotated Sorted Array II
#### Difficulty: Hard
#### Date: 2018/2/21
#### Solution
```
1. 遍历数组， 比较当前数和下一个数，若当前数大于下一个数，那最小值就是下一个数，结束
2. 同153题，有重复值不影响
```
#### Note
``` 
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/fmirsaII154.cpp)
---
### #155 Min Stack
#### Difficulty: Easy
#### Date: 2018/2/22
#### Solution
```
1. 用一个最小栈来保存数值栈的最小值的索引，最小栈的top表示的是数值栈的最小值
2. 当push时，先取出最小栈的栈顶值作为索引，找到数值栈的最小值，若该值比push的值还小的话，则将新的数值栈的top push到最小栈
3. 当pop时，若数值栈的最小值pop了，则最小栈也pop一个
```
#### Note
``` 
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/ms155.cpp)
--- 
### #160 Intersection of Two Linked Lists
#### Difficulty: Easy
#### Date: 2018/2/21
#### Solution
```
1. 先计算链表A和B的长度，长的那个从与短的相同长度的结点开始，比较A和B的每个结点
2. 若有相同结点则返回该结点，否则返回NULL
```
#### Note
```
1. 百度大法好
2. 也可以将一个链表首尾相连后通过快慢指针来计算连接点
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/iotll160.cpp)
---
### #162 Find Peak Element
#### Difficulty: Medium
#### Date: 2018/2/22
#### Solution
```
1. 遍历数组，如果当前值小于下一个值，则返回当前值的索引
2. 否则返回最后一个值的索引
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/fpe162.cpp)
---
### #165 Compare Version Numbers
#### Difficulty: Medium
#### Date: 2018/2/22
#### Solution
```
1. 根据"."来分隔字符串来得到每个数字
2. 比较两个字符串对应的数字
```
#### Note
```
1. 1和1.0返回0
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/cvn165.cpp)
---
### #166 Fraction to Recurring Decimal
#### Difficulty: Medium
#### Date: 2018/2/24
#### Solution
```
1. 注意界限问题
2. 将int转化为long long int
3. 用hash表来记录，key是当前余数，value是当前结果字符串的长度，如果余数已经存在于hash表里则在之前的相同余数和当前余数间插入"()",并返回
4. 如果余数为0，则直接返回
```
#### Note
```
1. 百度大法好
2. abs问题，返回值和参数要一致，否则会出错
3. string.insert来插入"("、")"
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/ftrd166.cpp)
---
### #167 Two Sum II - Input array is sorted
#### Difficulty: Easy
#### Date: 2018/2/22
#### Solution
```
1. k Sum问题
2. 夹逼
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/tsII167.cpp)
---
### #168 Excel Sheet Column Title
#### Difficulty: Easy
#### Date: 2018/2/22
#### Solution
```
1. 用A~Z表示26进制数
```
#### Note
```
1. 每次取模运算时都要把被取模数自减1
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/esct168.cpp)
---
### #169 Majority Element
#### Difficulty: Easy
#### Date: 2018/2/23
#### Solution
```
1. 用hash表来count，超过n/2则返回
```
#### Note
```
1. 可以排序后来count
2. 通过Boyer-Moore投票算法，即选出的候选人为1，非候选人为-1，当count为0时，选择新的候选人，最后返回候选人，这个也就是互相抵消后得到结果
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/me169.cpp)
---
### #171 Excel Sheet Column Number
#### Difficulty: Easy
#### Date: 2018/2/22
#### Solution
```
1. 用A~Z表示26进制数
2. 26进制转换为10进制
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/escn171.cpp)
---
### #172 Factorial Trailing Zeroes
#### Difficulty: Easy
#### Date: 2018/2/22
#### Solution
```
1. 10由2和5这两个素数相乘得来
2. 5数目肯定比2的数目多，所以计算5的数目就行
3. 通过p = n / pow(5, i), 计算p > 0的总和
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/ftz172.cpp)
---
### #173 Binary Search Tree Iterator
#### Difficulty: Medium
#### Date: 2018/2/23
#### Solution
```
1. 中序遍历，将结果保存在队列里
2. 每次next则依次从队列取数
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/bsti173.cpp)
---
### #179 Largest Number
#### Difficulty: Medium
#### Date: 2018/2/23
#### Solution
```
1. 将int装换成string，然后快排，最后拼凑
2. sort的比较函数实现采用了递归，如果字符串a是字符串b的首部子串，那么递归比较b剩下部分与a的大小关系
```
#### Note
```
1. sort的比较函数必须写在类外部（全局区域）或声明为静态函数
2. 还有更好的比较方法，用 a + b 与 b + a比较，代表了a和b的大小关系，而且连接后长度相等
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/bsti173.cpp)
---
### #187 Repeated DNA Sequences
#### Difficulty: Medium
#### Date: 2018/2/23
#### Solution
```
1. 将A、C、G、T用2个比特压缩，用0~3表示
2. 遍历字符串中的每个字符，通过比特的移位来计算下一个子字符串
3. 用hash表来记录子字符串的次数
```
#### Note
```
1. 百度大法好
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/rds187.cpp)
---
### #189 Rotate Array
#### Difficulty: Easy
#### Date: 2018/2/24
#### Solution
```
1. 判断往前插和往后插的值的数目，选择步骤最少的那种
2. 通过push_back、pop_back和erase来操作
3. k要取模数组的长度后更新
```
#### Note
```
1. 也可以通过旋转交换来达到目标
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/ra189.cpp)
---
### #190 Reverse Bits
#### Difficulty: Easy
#### Date: 2018/2/24
#### Solution
```
1. 移位操作
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/rb190.cpp)
---
### #191 Number of 1 Bits
#### Difficulty: Easy
#### Date: 2018/2/24
#### Solution
```
1. 移位操作
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/no1b191.cpp)
---
### #198 House Robber
#### Difficulty: Easy
#### Date: 2018/2/24
#### Solution
```
1. 动态规划
2. 递归时用dp数组来保存，否则会超时
3. 可以通过迭代来计算
4. 如果选择了抢劫上一个屋子，那么就不能抢劫当前的屋子，所以最大收益就是抢劫上一个屋子的收益，f(n - 1)
5. 如果选择抢劫当前屋子，就不能抢劫上一个屋子，所以最大收益是到上一个屋子的上一个屋子为止的最大收益，加上当前屋子里有的钱，f(n - 2) + num[n]
```
#### Note
```
1. 百度大法好
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/hr198.cpp)
---
### #199 Binary Tree Right Side View
#### Difficulty: Medium
#### Date: 2018/2/24
#### Solution
```
1. 层次遍历
2. 返回每一层的最后一个数
```
#### Note
```
1. 使用STL中queue数据结构实现更加简单
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/btrsv199.cpp)
---
### #200 Number of Islands
#### Difficulty: Medium
#### Date: 2018/2/24
#### Solution
```
1. 递归
2. 深度优先遍历
3. visited表
```
#### Note
```
1. 也可以使用层次遍历
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/nof200.cpp)
---
### #201 Bitwise AND of Numbers Range
#### Difficulty: Medium
#### Date: 2018/2/27
#### Solution
```
1. 将m和n异或后得tmp
2. 获取tmp的最大有效位top
3. 计算mask: (1 << (top + 1)) - 1
4. 结果为 m & ~mask
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/baonr201.cpp)
---
### #202 Happy Number
#### Difficulty: Easy
#### Date: 2018/2/27
#### Solution
```
1. 按照題目要求走
2. 用set保存之前的sum，如果已经存在则返回false
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/hn202.cpp)
---
### #203 Remove Linked List Elements
#### Difficulty: Easy
#### Date: 2018/2/27
#### Solution
```
1. 链表删除元素操作
```
#### Note
```
1. 设置一个头结点，简化当要删除链表首部结点的操作
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/rlle203.cpp)
---
### #204 Count Primes
#### Difficulty: Easy
#### Date: 2018/2/27
#### Solution
```
1. 埃拉托斯特尼筛法（素数筛）
2. 给出要筛数值的范围n，找出sqrt{n}以内的素数。 先用2去筛，即把2留下，把2的倍数剔除掉；再用下一个素数，也就是3筛，把3留下，把3的倍数剔除掉；接下去用下一个素数5筛，把5留下，把5的倍数剔除掉；不断重复下去......
```
#### Note
```
1. 百度大法好
2. 用vector比set效率高
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/cp204.cpp)
---
### #205 Isomorphic Strings
#### Difficulty: Easy
#### Date: 2018/2/27
#### Solution
```
1. 用map建立字符串s和t的映射,若s中两个相同的字符映射的字符不同则返回false
2. 用set保存已经访问过的t的字符，如果map未建立的映射的value已经出现在set中则返回false
```
#### Note
```
1. 更简单的方法，用两个数组保存当前访问的字符在上一次出现的索引，若不相等则返回false，否则更新当前字符的索引
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/is205.cpp)
---
### #206 Reverse Linked List
#### Difficulty: Easy
#### Date: 2018/2/27
#### Solution
```
1. 迭代方法： 1->2->3->4  =>  3->4 and 2->1
2. 递归方法： 1->2->3->4  =>  1->2<-3<-4
```
#### Note
```
1. 百度大法好
2. 想复杂了，不需要先遍历到尾部，时间复杂度是O(n)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/rll206.cpp)
---
### #207 Course Schedule
#### Difficulty: Medium
#### Date: 2018/2/28
#### Solution
```
1. 图判断是否有回路
2. 深度优先遍历
3. 通过marked来记录访问过的结点，onStack来判断当前路径有回路
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/cs207.cpp)
---
### #208 Implement Trie (Prefix Tree)
#### Difficulty: Medium
#### Date: 2018/2/28
#### Solution
```
1. 三向单词查找树的操作
```
#### Note
```
1. 参考书本上的，用的递归
2. 自己实现的是迭代的，出错了
3. 也可以用R向单词查找树
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/it208.cpp)
---
### #209 Minimum Size Subarray Sum
#### Difficulty: Medium
#### Date: 2018/3/1
#### Solution
```
1. 用两个指针分别指向子数组的首尾，计算长度，然后判断是否大于等于s并且比当前最小值小，如果是的话更新当前最小值
2. 初始时，两个指针都指向数组首部，之后尾指针向后移动，直到和大于等于s，之后移动首指针直到和小于s，以此往复
```
#### Note
```
1. 百度大法好
2. 和第53题类似
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/msss209.cpp)
---
### #210 Course Schedule II
#### Difficulty: Medium
#### Date: 2018/3/1
#### Solution
```
1. 拓扑排序
2. 改进第207题判断图是否有环的问题
3. 后序输出
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/csII210.cpp)
---
### #211 Add and Search Word - Data structure design
#### Difficulty: Medium
#### Date: 2018/3/1
#### Solution
```
1. R向单词查找树
2. 如果遇到'.'则查找所有子树
3. 只要有一个返回true，整个search函数就返回true
4. DFS
```
#### Note
```
1. 百度大法好
2. 自己改的三向单词查找树最后几个测试集没通过
3. R向单词查找树实现更简单
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/aasw211.cpp)
---
### #212 Word Search II
#### Difficulty: Hard
#### Date: 2018/3/2
#### Solution
```
1. 如果还按照DFS回溯的方法，逐个检查每个word是否在board里，显然效率是比较低的
2. 我们可以利用Trie数据结构，也就是前缀树。然后dfs时，如果当前形成的单词不在Trie里，就没必要继续dfs下去了
3. 如果当前字符串在trie里，就说明board可以形成这个word
```
#### Note
```
1. 百度大法好
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/wsII212.cpp)
---
### #213 House Robber II
#### Difficulty: Medium
#### Date: 2018/3/2
#### Solution
```
1. 动态规划
2. 和198题类似
3. 分别去掉第一家和最后一家计算，最后取两个的最大值
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/hrII213.cpp)
---
### #215 Kth Largest Element in an Array
#### Difficulty: Medium
#### Date: 2018/3/2
#### Solution
```
1. 利用快排的思想获取第k大的数
```
#### Note
```
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/kleiaa215.cpp)
---
### #216 Combination Sum III
#### Difficulty: Medium
#### Date: 2018/3/3
#### Solution
```
1. 按照题目思路采用递归
```
#### Note
```
1. 若i < n，则后面更大的i不需要计算了
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/CSIII216.cpp)
---
### #217 Contains Duplicate
#### Difficulty: Easy
#### Date: 2018/3/3
#### Solution
```
1. 用hash表记录
```
#### Note
```
1. 也可以用排序方法
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/cd217.cpp)
---
### #219 Contains Duplicate II
#### Difficulty: Easy
#### Date: 2018/3/3
#### Solution
```
1. 用hash表记录
2. 比较相同的两个key的索引值是不是小于等于k，若大于则更新value
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/cdII219.cpp)
---
### #220 Contains Duplicate III
#### Difficulty: Medium
#### Date: 2018/3/3
#### Solution
```
1. 用hash表记录
2. 通过k来确定滑动窗口
3. 遍历窗口内的每个元素，取比nums[i] - t最接近的上界，比较|tmp - nums[i]| <= t, 返回true
4. 否则移动滑动窗口
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试
4. 百度大法好
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/cdIII220.cpp)
---
### #221 Maximal Square
#### Difficulty: Medium
#### Date: 2018/3/4
#### Solution
```
1. 优化时间复杂度到O(n^2)
2. 做法是使用DP，简历一个二维dp数组，其中dp[i][j]表示到达(i, j)位置所能组成的最大正方形的边长。
3. 我们首先来考虑边界情况，也就是当i或j为0的情况，那么在首行或者首列中，必定有一个方向长度为1，那么就无法组成长度超过1的正方形，最多能组成长度为1的正方形，条件是当前位置为1。边界条件处理完了，再来看一般情况的递推公式怎么办，对于任意一点dp[i][j]，由于该点是正方形的右下角，所以该点的右边，下边，右下边都不用考虑，关心的就是左边，上边，和左上边。
4. 这三个位置的dp值suppose都应该算好的，还有就是要知道一点，只有当前(i, j)位置为1，dp[i][j]才有可能大于0，否则dp[i][j]一定为0。当(i, j)位置为1，此时要看dp[i-1][j-1], dp[i][j-1]，和dp[i-1][j]这三个位置，我们找其中最小的值，并加上1，就是dp[i][j]的当前值了，这个并不难想，毕竟不能有0存在，所以只能取交集，最后再用dp[i][j]的值来更新结果res的值即可
5. 进一步优化空间复杂度，此时只需要用一个一维数组就可以解决，为了处理边界情况，padding了一位，所以dp的长度是m+1，然后还需要一个变量pre来记录上一个层的dp值，我们更新的顺序是行优先，就是先往下遍历，用一个临时变量t保存当前dp值，然后看如果当前位置为1，则更新dp[i]为dp[i], dp[i-1], 和pre三者之间的最小值，再加上1，来更新结果res，如果当前位置为0，则重置当前dp值为0，因为只有一维数组，每个位置会被重复使用
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试
4. 百度大法好
5. 也有brute force方法，主要是可以通过将1相加得到sum来判断是否是正方形, 时间复杂度O(n^3)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/ms221.cpp)
---
### #222 Count Complete Tree Nodes
#### Difficulty: Medium
#### Date: 2018/3/4
#### Solution
```
1. 用暴力法, recursive求会超时 O(N).   
2. 如果从某节点一直向左的高度 = 一直向右的高度, 那么以该节点为root的子树一定是complete binary tree. 
3. 而 complete binary tree的节点数,可以用公式算出 2^h - 1. 如果高度不相等, 则递归调用 return countNode(left) + countNode(right) + 1.  复杂度为O(h^2) 
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试
4. 百度大法好
5. 用原方法会超时
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/cctn222.cpp)
---
### #223 Rectangle Area
#### Difficulty: Medium
#### Date: 2018/3/4
#### Solution
```
1. 尝试先找出所有的不相交的情况，只有四种，一个矩形在另一个的上下左右四个位置不重叠，这四种情况下返回两个矩形面积之和
2. 其他所有情况下两个矩形是有交集的，这时候我们只要算出长和宽，即可求出交集区域的大小，然后从两个巨型面积之和中减去交集面积就是最终答案
3. 求交集区域的长和宽也不难，由于交集都是在中间，所以横边的左端点是两个矩形左顶点横坐标的较大值，右端点是两个矩形右顶点的较小值，同理，竖边的下端点是两个矩形下顶点纵坐标的较大值，上端点是两个矩形上顶点纵坐标的较小值
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试
4. 百度大法好
5. 审题有误，想的是求交集
6. 没想到求min和max来求交集的坐标点
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/ra223.cpp)
---
### #225 Implement Stack using Queues
#### Difficulty: Easy
#### Date: 2018/3/5
#### Solution
```
1. 用两个队列实现栈
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(没做)
4. 对STL的queue操作不熟悉
5. 还有通过一个queue来实现的解法，通过把前面的数转移到新插入的后面来实现逆序，这样新插入的数就到了queue的首部
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/isuq225.cpp)
---
### #226 Invert Binary Tree
#### Difficulty: Easy
#### Date: 2018/3/5
#### Solution
```
1. 左子树和右子树替换
2. 递归
3. 也可以用广度优先遍历来做
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/ibt226.cpp)
---
### #227 Basic Calculator II
#### Difficulty: Medium
#### Date: 2018/3/5
#### Solution
```
1. 用栈来保存操作数
2. 当遇到操作符时，将栈里面的操作数push出来，用之前的操作符计算
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(没做)
4. 百度大法好
5. 把减法转化成加法
6. 计算式之前添加 ( 0 + )，统一计算步骤
7. 最后只要把所有加法相加就行
8. 只用一个栈来保存操作符即可
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/bcII227.cpp)
---
### #228 Summary Ranges
#### Difficulty: Medium
#### Date: 2018/3/5
#### Solution
```
1. 遍历一遍数组即可，每次检查下一个数是不是递增的，如果是，则继续往下遍历，如果不是了，我们还要判断此时是一个数还是一个序列，一个数直接存入结果，序列的话要存入首尾数字和箭头“->"
2. 需要两个变量i和j，其中i是连续序列起始数字的位置，j是连续数列的长度，当j为1时，说明只有一个数字，若大于1，则是一个连续序列
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(没做)
4. 百度大法好
5. 原来的思路是用二分法，但是mid的连接问题没法解决
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/sr228.cpp)
---
### #229 Majority Element II
#### Difficulty: Medium
#### Date: 2018/3/6
#### Solution
```
1. 找出两个候选众数进行投票，需要两遍遍历，第一遍历找出两个候选众数，第二遍遍历重新投票验证这两个候选众数是否为众数即可
2. 选候选众数方法和前面那篇Majority Element 求众数一样，由于之前那题题目中限定了一定会有众数存在，故而省略了验证候选众数的步骤，这道题却没有这种限定，即满足要求的众数可能不存在，所以要有验证
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(没做)
4. 百度大法好
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/meII229.cpp)
---
### #230 Kth Smallest Element in a BST
#### Difficulty: Medium
#### Date: 2018/3/6
#### Solution
```
1. 中序遍历
2. 递归
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/kseiab230.cpp)
---
### #231 Power of Two
#### Difficulty: Easy
#### Date: 2018/3/6
#### Solution
```
1. 取模2判断这种效率最差
2. 注意负数、0和1的情况
```
#### Note
```
1. 功能测试
2. 边界测试(no)
3. 负面测试(no)
4. 位操作更快
5. n & (n - 1) == 0 表示是2的幂
6. 百度大法好
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/pot231.cpp)
---
### #232 Implement Queue using Stacks
#### Difficulty: Easy
#### Date: 2018/3/6
#### Solution
```
1. 用一个栈来实现
2. 每次push操作之前用一个临时栈把当前栈的值都保存，再把值push到当前栈，最后恢复临时栈的值
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/iqus232.cpp)
---
### #234 Palindrome Linked List
#### Difficulty: Easy
#### Date: 2018/3/7
#### Solution
```
1. 快慢指针找到链表中点
2. 慢指针指向的后半部分翻转
3. 比较两个链表
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/pII234.cpp)
---
### #235 Lowest Common Ancestor of a Binary Search Tree
#### Difficulty: Easy
#### Date: 2018/3/7
#### Solution
```
1. 二分法
2. 对于二叉搜索树，公共祖先的值一定大于等于较小的节点，小于等于较大的节点。换言之，在遍历树的时候，如果当前结点大于两个节点，则结果在当前结点的左子树里，如果当前结点小于两个节点，则结果在当前节点的右子树里
3. 深度优先标记
4. 可以用深度优先搜索，从叶子节点向上，标记子树中出现目标节点的情况。如果子树中有目标节点，标记为那个目标节点，如果没有，标记为null。显然，如果左子树、右子树都有标记，说明就已经找到最小公共祖先了。如果在根节点为p的左右子树中找p、q的公共祖先，则必定是p本身
5. 换个角度，可以这么想：如果一个节点左子树有两个目标节点中的一个，右子树没有，那这个节点肯定不是最小公共祖先。如果一个节点右子树有两个目标节点中的一个，左子树没有，那这个节点肯定也不是最小公共祖先。只有一个节点正好左子树有，右子树也有的时候，才是最小公共祖先
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
4. 注意二叉搜索数的特性
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/lcaoabst235.cpp)
---
### #236 Lowest Common Ancestor of a Binary Tree
#### Difficulty: Medium
#### Date: 2018/3/7
#### Solution
```
1. 深度优先标记
2. 可以用深度优先搜索，从叶子节点向上，标记子树中出现目标节点的情况。如果子树中有目标节点，标记为那个目标节点，如果没有，标记为null。显然，如果左子树、右子树都有标记，说明就已经找到最小公共祖先了。如果在根节点为p的左右子树中找p、q的公共祖先，则必定是p本身
3. 换个角度，可以这么想：如果一个节点左子树有两个目标节点中的一个，右子树没有，那这个节点肯定不是最小公共祖先。如果一个节点右子树有两个目标节点中的一个，左子树没有，那这个节点肯定也不是最小公共祖先。只有一个节点正好左子树有，右子树也有的时候，才是最小公共祖先
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/lcaoabt236.cpp)
---
### #237 Delete Node in a Linked List
#### Difficulty: Easy
#### Date: 2018/3/7
#### Solution
```
1. 删除一个结点主要是删除它的值
2. 将后面结点的值覆盖当前结点，然后删除后面的结点
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/dniall237.cpp)
---
### #238 Product of Array Except Self
#### Difficulty: Medium
#### Date: 2018/3/7
#### Solution
```
1. 对于某一个数字，如果我们知道其前面所有数字的乘积，同时也知道后面所有的数乘积，那么二者相乘就是我们要的结果，所以我们只要分别创建出这两个数组即可，分别从数组的两个方向遍历就可以分别创建出乘积累积数组
2. 对上面的方法进行空间上的优化，由于最终的结果都是要乘到结果res中，所以我们可以不用单独的数组来保存乘积，而是直接累积到res中，我们先从前面遍历一遍，将乘积的累积存入res中，然后从后面开始遍历，用到一个临时变量right，初始化为1，然后每次不断累积，最终得到正确结果
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
4. 百度大法好
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/poaes238.cpp)
---
### #240 Search a 2D Matrix II
#### Difficulty: Medium
#### Date: 2018/3/11
#### Solution
```
1. 发现有两个位置的数字很有特点，左下角和右上角的数。左下角往上所有的数变小，往右所有数增加，那么我们就可以和目标数相比较，如果目标数大，就往右搜，如果目标数小，就往左搜。这样就可以判断目标数是否存在。
2. 当然我们也可以把起始数放在右上角，往左和下搜，停止条件设置正确就行。
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
4. 百度大法好
5. 思路类似但是选择的开始点有误, 都是把矩阵查找范围不断缩小
6. 是否可以在其中加入二分法
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/sa2mII240.cpp)
---
### #241 Different Ways to Add Parentheses
#### Difficulty: Medium
#### Date: 2018/3/11
#### Solution
```
1. 分治法
2. 对于输入字符串，若其中有运算符，则将其分为两部分，分别递归计算其值，然后将左值集合与右值集合进行交叉运算，将运算结果放入结果集中；若没有运算符，则直接将字符串转化为整型数放入结果集中
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
4. 百度大法好
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/dwtap241.cpp)
---
### #242 Valid Anagram
#### Difficulty: Easy
#### Date: 2018/3/11
#### Solution
```
1. 先比较两个字符串的长度
2. 用map来保存第一个字符串的字母出现的次数
3. 遍历第二个字符串的过程中将相同字母出现的次数减去直至都为0，若有没出现过的字母直接返回false
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/sa2mII240.cpp)
---
### #257 Binary Tree Paths
#### Difficulty: Easy
#### Date: 2018/3/11
#### Solution
```
1. DFS
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/btp257.cpp)
---
### #258 Add Digits
#### Difficulty: Easy
#### Date: 2018/3/12
#### Solution
```
1. 求数根，所谓树根，就是将大于10的数的各个位上的数字相加，若结果还大于10的话，则继续相加，直到数字小于10为止
2. 每9个一循环，所有大于9的数的树根都是对9取余，那么对于等于9的数对9取余就是0了，为了得到其本身，而且同样也要对大于9的数适用，我们就用(n-1)%9+1这个表达式来包括所有的情况
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
4. 百度大法好，获得O(1)的时间复杂度
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/ad258.cpp)
---
### #260 Single Number III
#### Difficulty: Medium
#### Date: 2018/3/13
#### Solution
```
1. 先把所有数异或
2. 再取异或中为1的位来把数分为两组，该位为1与不为1的
3. 分别把每组的各个数异或得到结果
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试
4. 百度大法好
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/snIII260.cpp)
---
### #263 Ugly Number
#### Difficulty: Easy
#### Date: 2018/3/13
#### Solution
```
1. 不停的除以 2、3、5
2. 注意负数
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/un263.cpp)
---
### #264 Ugly Number II
#### Difficulty: Medium
#### Date: 2018/3/13
#### Solution
```
1. 丑陋数序列可以拆分为下面3个子列表：

(1) 1x2,  2x2, 2x2, 3x2, 3x2, 4x2, 5x2...
(2) 1x3,  1x3, 2x3, 2x3, 2x3, 3x3, 3x3...
(3) 1x5,  1x5, 1x5, 1x5, 2x5, 2x5, 2x5...
2. 仔细观察上述三个列表，我们可以发现每个子列表都是一个丑陋数分别乘以2,3,5，而要求的丑陋数是从已经生成的序列中取出来的，我们每次都从三个列表中取出当前最小的那个加入序列
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
4. 百度大法好
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/unII264.cpp)
---
### #268 Missing Number
#### Difficulty: Easy
#### Date: 2018/3/13
#### Solution
```
1. 计算0到n的和再减去当前数组
2. 也可以用完整的数组和当前数组异或
3. 也可以二分查找，但要先快排
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/mn268.cpp)
---
### #274 H-Index
#### Difficulty: Medium
#### Date: 2018/3/13
#### Solution
```
1. 快排(从大到小)
2. 遍历数组，当(i + 1) > citations[i]时返回i
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/hi274.cpp)
---
### #275 H-Index II
#### Difficulty: Medium
#### Date: 2018/3/13
#### Solution
```
1. 类似于274题，只是数组排列是从小到大
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/hiII275.cpp)
---
### #278 First Bad Version
#### Difficulty: Easy
#### Date: 2018/3/13
#### Solution
```
1. 二分查找
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
4. 百度大法好，若lo和right非常大，则会溢出
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/fbv278.cpp)
---
### #275 H-Index II
#### Difficulty: Medium
#### Date: 2018/3/13
#### Solution
```
1. 类似于274题，只是数组排列是从小到大
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/hiII275.cpp)
---
### #279 Perfect Squares
#### Difficulty: Medium
#### Date: 2018/3/13
#### Solution
```
1. 动态规划，最常规的做法，用dp[n + 1]保存每个数最小的组成数目
2. 根据四平方和定理，任意一个正整数均可表示为4个整数的平方和，其实是可以表示为4个以内的平方数之和，那么就是说返回结果只有1,2,3或4其中的一个
3. 首先我们将数字化简一下，由于一个数如果含有因子4，那么我们可以把4都去掉，并不影响结果，比如2和8,3和12等等，返回的结果都相同
4. 还有一个可以化简的地方就是，如果一个数除以8余7的话，那么肯定是由4个完全平方数组成，
5. 那么做完两步后，一个很大的数有可能就会变得很小了，大大减少了运算时间，下面我们就来尝试的将其拆为两个平方数之和，如果拆成功了那么就会返回1或2，因为其中一个平方数可能为0. (注：由于输入的n是正整数，所以不存在两个平方数均为0的情况)
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
4. 百度大法好
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/ps279.cpp)
---
### #283 Move Zeroes
#### Difficulty: Easy
#### Date: 2018/3/13
#### Solution
```
1. 用两个指针，一个不停的向后扫，找到非零位置，然后和前面那个指针交换位置即可
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/mz283.cpp)
---
### #290 Word Pattern
#### Difficulty: Easy
#### Date: 2018/3/13
#### Solution
```
1. 用hash表来记录
2. 可以通过istringstream in(str); in >> word;来分离字符
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/wp290.cpp)
---
### #292 Nim Game
#### Difficulty: Easy
#### Date: 2018/3/13
#### Solution
```
1. 每人每步最多划三条线，所以线的总是至少为4条。当线的总数为4条的时候，不管先手划几条线，后手都有应对的方法，先手必输
2. 所以你会发现8条也是必输，8条线可以分成两个部分，每个部分四条线。自然先手还是必输。4这个数字还真是不太吉利
3. 当线的总数为5条的时候，先手先划掉一条线，后手就等于是在4条线的情况下先手，自然后手输
4. Nim游戏是博弈论中最经典的模型
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/ng292.cpp)
---
### #300 Longest Increasing Subsequence
#### Difficulty: Medium
#### Date: 2018/3/13
#### Solution
```
1. 动态规划
2. 先建立一个数组 ends，把首元素放进去，然后比较之后的元素.
3. 如果遍历到的新元素比ends数组中的首元素小的话，替换首元素为此新元素;
4. 如果遍历到的新元素比ends数组中的末尾元素还大的话，将此新元素添加到ends数组末尾(注意不覆盖原末尾元素);
5. 如果遍历到的新元素比ends数组首元素大，比尾元素小时，此时用二分查找法找到第一个不小于此新元素的位置，覆盖掉位置的原来的数字;
6. 以此类推直至遍历完整个 nums 数组，此时 ends 数组的长度就是我们要求的 LIS 的长度，特别注意的是 ends 数组的值可能不是一个真实的LIS，比如若输入数组nums为 {4, 2， 4， 5， 3， 7}，那么算完后的ends数组为{2， 3， 5， 7}，可以发现它不是一个原数组的LIS，只是长度相等而已，千万要注意这点
```
#### Note
```
1. 功能测试
2. 边界测试
3. 负面测试(no)
4. 百度大法好，O(nlogn)
```
[code link](https://github.com/chenup/LeetCode/blob/master/code/lis300.cpp)
---







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
#### Date: 2017/8/24
#### Solution
```

```
#### Note
```

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

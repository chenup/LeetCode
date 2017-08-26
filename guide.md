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
#### Date: 2017/8/2
#### Solution
```
1. 用一个数组保存当前字符串里字符出现的位置，如果没有则为-1
2. 遍历整个字符串，通过cur_l表示当前子字符的长度，max_l表示最大的子字符串的长度,用last表示最新出现的重复字符的位置
```
#### Note
```
1. 重复字符不一定连续，重复字符中间的字符不重复 
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
#### Date: 2017/8/13
#### Solution
```
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
#### Date: 2017/8/26
#### Solution
```

```
#### Note
```

```
[code link](https://github.com/chenup/LeetCode/blob/master/cwmw11.cpp)
---
### #12 Integer to Roman
#### Difficulty: Medium
#### Date: 2017/8/26
#### Solution
```

```
#### Note
```

```
[code link](https://github.com/chenup/LeetCode/blob/master/itr12.cpp)
---
### #13 Roman to Integer 
#### Difficulty: Easy
#### Date: 2017/8/26
#### Solution
```

```
#### Note
```

```
[code link](https://github.com/chenup/LeetCode/blob/master/rti.cpp)
---

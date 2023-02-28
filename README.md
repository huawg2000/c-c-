# cpp

本文题源和学习路径来自于[代码随想录](https://programmercarl.com/)

## 数组
### 二分查找

二分查找运用的前提

  1.数组有序

  2.数组没有重复元素

**边界条件**

  1.本文只选讲左闭右闭（好理解，前后都要移位），此时left==right有意义
  ```cpp
  while(left <= right)
  ```

  2.因为当前这个nums[i]必定不是target，所以在后续二分时要移位
  >     
  ```cpp
    if(nums[i] < target) {
        left = i + 1;
        i = left + (right - left) / 2;
    }
  ```
  >     
  ```cpp
    if(nums[i] > target) {
        right = i - 1; 
        i = left + (right - left) / 2;
    }
  ```

参考代码

  >
  ```cpp
    int search(vector<int>& nums, int target) {
        int i = (nums.size()-1)/2;
        int left = 0;
        int right = nums.size()-1;
        while(left <= right) { 
            if(nums[i] == target)return i; //当前数组i位置的元素已经参与比较，所以后续二分需要移位(+1/-1)
            else if(nums[i] < target) {
                left = i + 1; //在当前位置处移位
                i = left + (right - left) / 2;
            }
            else if(nums[i] > target) {
                right = i - 1; //在当前位置处移位
                i = left + (right - left) / 2;
            }
        }
        return -1; //找不到返回-1
    }
  ```

参考例题

1.[二分查找](https://leetcode.cn/problems/binary-search/)
本文[参考代码](leetcode//../src//数组/二分查找/704二分查找.cpp)

2.[搜索插入位置](https://leetcode.cn/problems/search-insert-position/)
本文[参考代码](leetcode//../src/数组/二分查找/35搜索插入位置.cpp)

3.[在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/)
本文[参考代码](leetcode//../src/数组/二分查找//34在排序数组中查找元素的第一个和最后一个位置.cpp)

4.[x的平方根](https://leetcode.cn/problems/sqrtx/)
本文[参考代码](leetcode//../src/数组/二分查找/69x的平方根.cpp)

5.[有效的完全平方数](https://leetcode.cn/problems/valid-perfect-square/)
本文[参考代码](leetcode//../src/数组/二分查找/367有效的完全平方数.cpp)
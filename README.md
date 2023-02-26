# cpp
## 数组
### 二分查找
二分查找运用的前提
  1.数组有序
  2.数组没有重复元素
**边界条件**
  1.左闭右闭，此时left==right有意义
  ```cpp
  while(left <= right)
  ```
  2.因为当前这个nums[i]必定不是target，所以在后续二分时要移动一个位置
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
        right = i - 1; //在当前位置处移位
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
        return -1;
    }
  ```
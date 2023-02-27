#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] == target)return mid; //找到则返回索引
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
        }
        /*
            执行完上述循环操作我们可以得到当前遍历的位置mid
            若是nums[mid] > target，则当前位置就是要插入的位置，后续数组元素向后移，直接返回mid即可
        */
        if(nums[mid] < target && mid != nums.size())return mid + 1; // 若是nums[mid] > target，则当前位置的下一个位置就是要插入的位置，后续数组元素向后移
        return mid;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    int target;
    cin >> target;
    s.searchInsert(nums,target);
    return 0;
}

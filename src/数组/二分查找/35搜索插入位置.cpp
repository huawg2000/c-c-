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
            if(nums[mid] == target)return mid;
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
        }
        if(nums[mid] < target && mid != nums.size())return mid + 1;
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

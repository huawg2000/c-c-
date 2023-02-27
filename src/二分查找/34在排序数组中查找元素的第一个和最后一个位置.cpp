#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int flag = -1;
        vector<int> res;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                flag = mid;
                break;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
        }

        if(flag == -1) {
            res.push_back(-1);
            res.push_back(-1);
        }
        else if(flag != -1) {
            int begin = flag;
            int end = flag;
            while(begin > 0 && nums[--begin] == target) {}
            if(nums[begin] != target)begin++;
            while(end < nums.size() -1 && nums[++end] == target) {}
            if(nums[end] != target)end--;
            res.push_back(begin);
            res.push_back(end);
        }
        return res;
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
    s.searchR(nums,target);
    return 0;
}
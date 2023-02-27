#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int flag = -1; //标记位，若flag = -1则表示没找到target，若找到了则标记target的位置
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

        if(flag == -1) { //没找到target
            res.push_back(-1);
            res.push_back(-1);
        }
        else if(flag != -1) { //找到target，前后搜索与target相同的值，注意边界的判定
            int begin = flag;
            int end = flag;
            while(begin > 0 && nums[--begin] == target) {} //代表begin前一个值与target作比较，跳出循环的可能有begin = 0，或者nums[begin-1] != target
            if(nums[begin] != target)begin++; //若跳出循环的是begin == 0则执行该语句
            while(end < nums.size() -1 && nums[++end] == target) {} //与begin同理，后一个值比较，不再赘述
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
    s.searchRange(nums,target);
    return 0;
}
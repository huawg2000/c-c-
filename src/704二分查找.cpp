#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
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
    s.search(nums,target);
    return 0;
}

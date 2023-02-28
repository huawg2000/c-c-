#include<iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)return 0;
        if(x == 1)return 1;
        int left = 0;
        int right = x;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(mid)if(x / mid == mid) return mid; //排除除0异常，若此时为平方数则直接返回
            else if(x / mid > mid) left = mid + 1;
            else if(x / mid < mid) right = mid - 1;
        }
        return right; //出循环后right < left，根据题目意思，应该返回向下取整的数字
    }
};

int main() {
    int n;
    Solution S;
    cin >> n;
    cout << S.mySqrt(n);
}
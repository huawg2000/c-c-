#include<iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return 1;
        if(num == 2) return 0;
        int left = 0;
        int right = num / 2;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(mid)if(num / mid == mid) { //此时找到的数已经是最接近完全平方数的数/小数，因精度原因这里显示相等，因此需要进一步判断
                if(mid * mid == num)return true; //不是精度的原因导致的相等
                else break; //是精度的原因导致的相等
            }
            else if(num / mid > mid)left = mid + 1;
            else if(num / mid < mid)right = mid - 1;
        }
        return false;
    }
};

int main() {
    int n;
    Solution S;
    cin >> n;
    if(S.isPerfectSquare(n))cout << n << " is a perfect square.";
    else cout << n << " isn't a perfect square.";
}
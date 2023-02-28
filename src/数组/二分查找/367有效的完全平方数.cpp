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
            if(mid)if(num / mid == mid) {
                if(mid * mid == num)return true;
                else break;
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
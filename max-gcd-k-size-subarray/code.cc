#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int maxGCDKSizeSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) {
        return -1; // Not enough elements in the array
    }

    int maxGCD = 0;
    for (int i = 0; i <= n - k; ++i) {
        int curGCD = nums[i];
        for (int j = 1; j < k; ++j) {
            curGCD = gcd(curGCD, nums[i + j]);
        }
        maxGCD = max(maxGCD, curGCD);
    }
    return maxGCD;
}

int main() {
// #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
// #endif
    int t;
    // cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n, k;
        // cout << "Enter the size of the array and subarray: ";
        cin >> n >> k;
        vector<int> nums(n);
        // cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << maxGCDKSizeSubarray(nums, k) << endl;
    }
    return 0;
}

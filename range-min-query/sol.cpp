#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to build the sparse table for range minimum queries
vector<vector<int>> buildSparseTable(const vector<int>& nums) {
    int n = nums.size();
    int logN = log2(n) + 1;

    // Initialize sparse table with -1
    vector<vector<int>> sparseTable(n, vector<int>(logN, -1));

    // Fill sparse table using dynamic programming
    for (int i = 0; i < n; ++i) {
        sparseTable[i][0] = i; // Each element itself is the minimum in the range [i, i]
    }

    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            int left = sparseTable[i][j - 1];
            int right = sparseTable[i + (1 << (j - 1))][j - 1];
            sparseTable[i][j] = (nums[left] <= nums[right]) ? left : right;
        }
    }

    return sparseTable;
}

// Function to perform range minimum query using sparse table
int rangeMinQuery(const vector<int>& nums, const vector<vector<int>>& sparseTable, int left, int right) {
    int k = log2(right - left + 1);
    int leftMinIndex = sparseTable[left][k];
    int rightMinIndex = sparseTable[right - (1 << k) + 1][k];
    return min(nums[leftMinIndex], nums[rightMinIndex]);
}

int main() {
    int numTestCases;
    cin >> numTestCases;

    while (numTestCases--) {
        int n, q;
        cin >> n >> q;

        // Read the array elements
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        // Build sparse table
        vector<vector<int>> sparseTable = buildSparseTable(nums);

        // Perform range minimum queries
        for (int i = 0; i < q; ++i) {
            int left, right;
            cin >> left >> right;
            int minVal = rangeMinQuery(nums, sparseTable, left, right);
            cout << minVal << " ";
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int solve(vector<int>& arr, int X, int N, int idx, int gval, vector<vector<int>>& dp) {
    if (idx == N) {
        if (gval == X)
            return 1;
        return 0;
    }

    if (dp[idx][gval] != -1)
        return dp[idx][gval];

    int ans = solve(arr, X, N, idx + 1, gval, dp);
    ans += solve(arr, X, N, idx + 1, gcd(gval, arr[idx]), dp);

    dp[idx][gval] = ans;

    return ans;
}

int totalValidSubsequences(vector<int>& arr, int X, int N) {
    int mx = *max_element(arr.begin(), arr.end());
    vector<vector<int>> dp(N + 1, vector<int>(mx + 1, -1));

    int count = solve(arr, X, N, 0, 0, dp);

    return count;
}

int main() {
// #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
// #endif

    int T;
    cin >> T;

    while (T--) {
        int N, X;
        cin >> N >> X;
        vector<int> arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }

        cout << totalValidSubsequences(arr, X, N) << endl;
    }

    return 0;
}

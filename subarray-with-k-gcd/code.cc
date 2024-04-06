#include <bits/stdc++.h>
using namespace std;

class Solution {
    // n2 logn
    public: int gcdd(int a, int b) {
        if (b == 0) return a;
        return gcdd(b, a % b);
    }
    int subarrayGCD(vector < int > & nums, int k) {
        int n = nums.size();
        vector < vector < int >> dp(n, vector < int > (n));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i == j)
                    dp[i][j] = nums[j];
                else
                    dp[i][j] = gcdd(dp[i][j - 1], nums[j]);
                if (dp[i][j] == k)
                    cnt++;
            }
        }
        return cnt;
    }
};

class Solution2 {
    // n log n
    public: vector < int > st;
    void allocate_memory(int n) {
        st.resize(4 * n);
        return;
    }
    public: int __gcd(int a, int b) {
        if (b == 0) return a;
        return __gcd(b, a % b);
    }
    void build(vector < int > & nums, int si, int sl, int sr) {
        if (sl == sr) {
            st[si] = nums[sl];
            return;
        }
        int mid = sl + (sr - sl) / 2;
        build(nums, 2 * si, sl, mid);
        build(nums, 2 * si + 1, mid + 1, sr);
        st[si] = __gcd(st[2 * si], st[2 * si + 1]); //gcd
        return;
    }
    int query(int si, int sl, int sr, int l, int r) {
        if (sl > r or sr < l) return 0;
        if (sl >= l and sr <= r) return st[si];
        int mid = sl + (sr - sl) / 2;
        int left = query(2 * si, sl, mid, l, r);
        int right = query(2 * si + 1, mid + 1, sr, l, r);
        return __gcd(left, right);
    }
    int subarrayGCD(vector < int > & nums, int k) {
        int n = nums.size();
        vector < int > terminations;
        for (int i = 0; i < n; i++) {
            if (nums[i] % k != 0) {
                nums[i] = -1;
                terminations.push_back(i);
            } else
                nums[i] = nums[i] / k;
        }
        allocate_memory(n);
        build(nums, 1, 0, n - 1);
        terminations.push_back(n);
        int i = 0, j = 0;
        int count = 0;
        while (i < n) {
            while (j < n and nums[j] != -1 and query(1, 0, n - 1, i, j) != 1)
                j++;
            if (j == n) break;
            if (nums[j] == -1) {
                i = j + 1;
                j++;
                continue;
            }
            int ind = lower_bound(terminations.begin(), terminations.end(), j) - terminations.begin();
            int n_ = terminations[ind];
            count += (n_ - j);
            i++;
            j = max(i, j);
        }
        return count;
    }
};

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> vec(n);
    for(int i = 0; i < n; ++i){
       cin>>vec[i];
    }
    Solution s1;
    Solution2 s2;
    cout<<s1.subarrayGCD(vec, k)<<endl;
    // cout<<s2.subarrayGCD(vec, k)<<endl;
}

int main(int argc, char const *argv[]){
    // #ifndef ONLINE_JUDGE
    // For getting input from in.txt file
    freopen("in.txt", "r", stdin);
    // Printing the Output to out.txt file
    freopen("out.txt", "w", stdout);
    // #endif
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}

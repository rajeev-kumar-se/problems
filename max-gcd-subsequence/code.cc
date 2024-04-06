#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int maxGCDSubsequenceRecursive(const vector<int>& nums, int i, int prevGCD) {
    if (i == nums.size())
        return prevGCD;

    // Including current element in the subsequence
    int includeCurrent = gcd(prevGCD, nums[i]);
    int includeResult = maxGCDSubsequenceRecursive(nums, i + 1, includeCurrent);

    // Excluding current element from the subsequence
    int excludeResult = maxGCDSubsequenceRecursive(nums, i + 1, prevGCD);

    // Return the maximum of both possibilities
    return max(includeResult, excludeResult);
}

int solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
       cin>>nums[i];
    }
    int result = maxGCDSubsequenceRecursive(nums, 0, 0);
    cout << result << endl;
    return 0;
}

int main(int argc, char const *argv[]){
// #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
// #endif    
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}




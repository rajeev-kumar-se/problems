#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxGCD(vector<int> arr, int n, int k) {
    int high = *std::max_element(arr.begin(), arr.end());
    vector<int> divisors(high + 1, 0 );

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= sqrt(arr[i]); j++) {
            if (arr[i] % j == 0) {
                divisors[j]++;
                if (j != arr[i] / j)
                    divisors[arr[i] / j]++;
            }
        }
    }

    for (int i = high; i >= 1; i--) {
        if (divisors[i] >= k)
            return i;
    }
    return 1; // default value if no suitable GCD found
}

void solve(){
    int k, n;
    cin>>n>>k;
    vector<int> vec(n,0);
    for(int i = 0; i < n; ++i){
       cin>>vec[i];
    }

    std::cout << findMaxGCD(vec, n, k)<<endl;
}

int main() {
// #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
// #endif
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

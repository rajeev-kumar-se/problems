#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    
    // Calculate the GCD of numbers from 1 to n
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        result = gcd(result, i);
    }
    
    cout << result << endl;
}

int main() {
// #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
// #endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
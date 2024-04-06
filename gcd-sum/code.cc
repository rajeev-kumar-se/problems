#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    int a, b;
    cin >> a >> b;
    int result = gcd(a, b);
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

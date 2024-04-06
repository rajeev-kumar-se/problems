#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
// #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
// #endif

    int T;
    cin >> T;

    while (T--) {
        int a, n;
        cin >> a >> n;
        
        // Calculate the gcd of the range
        int result = a;
        for (int i = 1; i <= n; ++i) {
            result = gcd(result, a + i);
        }

        cout << result << endl;
    }

    return 0;
}

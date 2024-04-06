#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            result = gcd(result, i);
        }
        cout << result << endl;
    }
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

string S; 
int m[18][90][90][2];
set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163 }; // 9*18

int dp(int p, int eps, int ops, int t) {
    if (p == S.size()) { 
        if (S.size() & 1) swap(ops, eps); 
        return primes.find(eps - ops) != primes.end() ? 1 : 0; 
    }
    if (m[p][eps][ops][t] == -1) { 
        int l = t ? S[p] - '0' : 9; 
        int ans1 = 0;
        for (int d = 0; d <= l; d++) {
            ans1 += dp(p + 1, p % 2 == 0 ? eps + d : eps, p % 2 == 1 ? ops + d : ops, t & (l == d));
        }
        m[p][eps][ops][t] = ans1; 
    }
    return m[p][eps][ops][t]; 
}

void solve() {
    ll l, r;
    cin >> l >> r, --l; 
    memset(m, -1, sizeof(m)); 
    S = to_string(l); 
    ll ansL = dp(0, 0, 0, 1); 

    memset(m, -1, sizeof(m)); 
    S = to_string(r); 
    ll ansR = dp(0, 0, 0, 1); 
    cout << ansR - ansL << endl;
}

int main() {
    ios::sync_with_stdio(0^0); cin.tie(nullptr);
    int testcases;
    cin >> testcases;
    while (testcases--) solve(); // Process each test case
    return EXIT_SUCCESS;
}

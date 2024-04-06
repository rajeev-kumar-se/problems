#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
const int MAXN = 100005;
const int K = 25; // Adjust as needed for log2(MAXN)

int sparse_table[MAXN][K + 1];
int logs[MAXN];

void preprocess(const vector<int>& arr, int N) {
    // Initialize logs array
    logs[1] = 0;
    for (int i = 2; i <= N; i++)
        logs[i] = logs[i / 2] + 1;

    // Construct sparse table
    for (int i = 0; i < N; i++)
        sparse_table[i][0] = arr[i];

    for (int j = 1; j <= K; j++) {
        for (int i = 0; i + (1 << j) <= N; i++) {
            sparse_table[i][j] = gcd(sparse_table[i][j - 1], sparse_table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int L, int R) {
    int j = logs[R - L + 1];
    return gcd(sparse_table[L][j], sparse_table[R - (1 << j) + 1][j]);
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    preprocess(arr, N);

    for (int q = 0; q < Q; ++q) {
        int L, R;
        cin >> L >> R;
        cout << query(L, R) << endl;
    }
}

int main() {
    // #ifndef ONLINE_JUDGE
    // For getting input from in.txt file
    freopen("in.txt", "r", stdin);
    // Printing the Output to out.txt file
    freopen("out.txt", "w", stdout);
    // #endif
    int t; cin>>t;
    while(t--)solve();
    return 0;
}

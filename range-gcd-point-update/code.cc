#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int build(int treeIdx, int left, int right) {
        if (left == right) {
            tree[treeIdx] = arr[left];
            return tree[treeIdx];
        }

        int mid = left + (right - left) / 2;
        int leftChild = 2 * treeIdx + 1;
        int rightChild = 2 * treeIdx + 2;

        int leftGCD = build(leftChild, left, mid);
        int rightGCD = build(rightChild, mid + 1, right);

        return tree[treeIdx] = gcd(leftGCD, rightGCD);
    }

    int updateUtil(int treeIdx, int left, int right, int idx, int val) {
        if (left == right && left == idx) {
            arr[idx] = val;
            return tree[treeIdx] = val;
        }

        int mid = left + (right - left) / 2;
        int leftChild = 2 * treeIdx + 1;
        int rightChild = 2 * treeIdx + 2;

        int leftGCD, rightGCD;
        if (idx <= mid)
            leftGCD = updateUtil(leftChild, left, mid, idx, val);
        else
            leftGCD = tree[leftChild];
        if (idx > mid)
            rightGCD = updateUtil(rightChild, mid + 1, right, idx, val);
        else
            rightGCD = tree[rightChild];

        return tree[treeIdx] = gcd(leftGCD, rightGCD);
    }

    int queryUtil(int treeIdx, int left, int right, int ql, int qr) {
        if (ql <= left && qr >= right)
            return tree[treeIdx];

        if (ql > right || qr < left)
            return 0;

        int mid = left + (right - left) / 2;
        int leftChild = 2 * treeIdx + 1;
        int rightChild = 2 * treeIdx + 2;

        int leftGCD = queryUtil(leftChild, left, mid, ql, qr);
        int rightGCD = queryUtil(rightChild, mid + 1, right, ql, qr);

        return gcd(leftGCD, rightGCD);
    }

public:
    SegmentTree(vector<int>& input) {
        n = input.size();
        arr = input;
        tree.assign(4 * n, 0);
        build(0, 0, n - 1);
    }

    void update(int idx, int val) {
        updateUtil(0, 0, n - 1, idx, val);
    }

    int query(int ql, int qr) {
        return queryUtil(0, 0, n - 1, ql, qr);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    SegmentTree st(arr);

    while(q--){
        int t;
        cin>>t;
        if(t){
            int idx, val;
            cin>>idx>>val;
            st.update(idx, val); 
        }else{
            int l, r;
            cin>>l>>r;
            cout << st.query(l, r) << endl; 
        }
    }
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

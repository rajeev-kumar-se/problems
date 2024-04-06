#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
using namespace std;
using ll = long long;
#define MOD int(1e9+7)
#define all(x) (x).begin(), (x).end()
#define rep(x, a, b) for(ll (x) = (a); (x) < (b); ++(x))
#define sz(x) ((int)x.size())
#define ub(v,x) upper_bound(all(v),x)
#define lb(v,x) lower_bound(all(v),x)
#define pb push_back
#define ff first
#define ss second
#define vll vector<ll>
#define pll pair<ll,ll>
#define tll tuple<ll, ll, ll>
#define readv(v) rep(i, 0, sz(v)){cin>>v[i];}
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;
// Debug 1
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B, typename C> ostream& operator<<(ostream &os, const tuple<A, B, C> &p) { return os << '(' << get<0>(p) << ", " << get<1>(p) << ", " << get<2>(p) << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os ; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
// Exponentiation
ll pow(ll a, ll b, ll m = MOD) { a %= m;ll res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1;}return res;}
// Mod
inline ll gcd(int a, int b){return b==0 ? a : gcd(b, a%b);}
inline tll ee(ll a, ll b){if(b==0) return {a, 1, 0};int d, x, y; tie(d, x, y) = ee(b, a%b);return {d, y, x - (a/b)*y};}
inline ll add(ll a, ll b){return (a%MOD + b%MOD)%MOD;}
inline ll sub(ll a, ll b){return (a%MOD - b%MOD)%MOD;}
inline ll mul(ll a, ll b){return (a%MOD *1LL* b%MOD)%MOD;}
inline ll divi(ll a, ll b){return mul(a, pow(b, MOD-2));}
// Moves
int dxk[8] ={2,2,-2,-2,1,1,-1,-1};
int dyk[8] ={1,-1,1,-1,2,-2,2,-2};
// Solve
void seive(){}
// Debug 2
template <typename T=ll> T rint(ll a, ll b) { return uniform_int_distribution<T>(a, b)(mt_rng);}
vector<ll> rvec(int N,int l, int r) { vector<ll> v(N); generate(v.begin(), v.end(), [&](){ return rint<ll>(l, r); }); return v;}

// Generate a random tree with 'n' vertices
vector<vector<int>> rTree(int n) {
    vector<vector<int>> tree(n);
    unordered_set<int> visited;
    for (int i = 1; i < n; ++i) {
        int parent = rint(0, i - 1);
        tree[parent].push_back(i);
        tree[i].push_back(parent);
        visited.insert(parent);
    }
    return tree;
}

// Generate a random graph with 'n' vertices and 'm' edges
vector<pair<int, int>> rGraph(int n, int m, bool cyclic, bool directed) {
    vector<pair<int, int>> edges;
    if (!cyclic && m > (n * (n - 1)) / 2) {
        cout << "Error: Too many edges requested for an acyclic graph with " << n << " vertices!" << endl;
        return edges;
    }
    if (cyclic && m > n * n) {
        cout << "Error: Too many edges requested for a cyclic graph with " << n << " vertices!" << endl;
        return edges;
    }
    unordered_set<int> visited;
    while (edges.size() < m) {
        int u = rint(0, n - 1);
        int v = rint(0, n - 1);
        if (!cyclic && u == v) continue; // Skip self loops in acyclic graph
        if (u != v && visited.find(u * n + v) == visited.end()) {
            edges.push_back({u, v});
            visited.insert(u * n + v);
            if (!directed)
                visited.insert(v * n + u);
        }
    }
    return edges;
}

// Print the given tree
void pTree(const vector<vector<int>>& tree) {
    cout << "Tree:\n";
    cout << "Number of vertices: " << tree.size() << endl;
    int edges = 0;
    for (int i = 0; i < tree.size(); ++i) {
        edges += tree[i].size();
    }
    cout << "Number of edges: " << edges / 2 << endl;
    for (int i = 0; i < tree.size(); ++i) {
        cout << "Node " << i << " connected to:";
        for (int neighbor : tree[i]) {
            cout << " " << neighbor;
        }
        cout << endl;
    }
}

// Print the given graph
void pGraph(const vector<pair<int, int>>& graph) {
    cout << "Graph:\n";
    unordered_set<int> vertices;
    for (auto [u, v] : graph) {
        vertices.insert(u);
        vertices.insert(v);
    }
    cout << "Number of vertices: " << vertices.size() << endl;
    cout << "Number of edges: " << graph.size() << endl;
    for (auto [u, v] : graph) {
        cout << "Edge: " << u << " - " << v << endl;
    }
}

// Generate random left-right queries from a given vector
template <typename T>
vector<pair<T, T>> rLR(const vector<T>& v) {
    vector<pair<T, T>> queries;
    random_device rd;
    mt19937 mt_rng(rd());
    
    // Generate queries
    for (size_t i = 0; i < v.size(); ++i) {
        uniform_int_distribution<size_t> dist(i, v.size() - 1);
        size_t l = dist(mt_rng);
        size_t r = dist(mt_rng);
        if (l > r) swap(l, r);
        queries.push_back({v[l], v[r]});
    }
    return queries;
}

// Print left-right queries
template <typename T>
void pLR(const vector<pair<T, T>>& queries) {
    cout << "Left-Right Queries:\n";
    for (const auto& query : queries) {
        cout << "(" << query.first << ", " << query.second << ")\n";
    }
}

// =========================================
string PROBLEM = "$file_name";
ofstream fout("./"+PROBLEM+".in");
// ========WRITE TEST CASE HERE=============

void writer(){
    // use: fout
    int no_of_testcases = 50;
    fout<<no_of_testcases<<endl;
    for (size_t i = 0; i < no_of_testcases; i++){
        //Generate a case
        
    }
}

// =========================================
void solve(){
    if (!fout.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }
    writer();
    fout.close();
    std::cout << "Testcases has been generated to "+PROBLEM+".in" << std::endl;
}
int main(){
    // ios::sync_with_stdio(0^0); cin.tie(nullptr);
    // seive();
    // btfc();
    // int testcases; cin>>testcases; while(testcases--) solve();
    solve();
    return EXIT_SUCCESS;
}

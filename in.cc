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
// Debug 2
template <typename T=ll> T rint(ll a, ll b) { return uniform_int_distribution<T>(a, b)(mt_rng);}
vector<ll> rvec(int N,int l, int r) { vector<ll> v(N); generate(v.begin(), v.end(), [&](){ return rint<ll>(l, r); }); return v;}
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
// =========================================
string PROBLEM = "$file_name";
std::ofstream fout("./"+PROBLEM+".in");
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

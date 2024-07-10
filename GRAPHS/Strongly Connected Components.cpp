#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
#define el << '\n'
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0) ;
ll bin_expo(ll base, ll pow, ll m) {
        if (pow == 0) return 1;ll ret = bin_expo(base, pow / 2, m) % m;
        if (pow & 1) return (ret % m * ret % m * base % m) % m;else return (ret % m * ret % m) % m;}
ll ncr(ll n , ll r) {ll mul = 1 ; for(ll i=1;i<=r;i++) {mul = mul * (n-i+1) ; mul = mul/i ; }return mul ; }
ll mod_add(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m; }
ll mod_sub(ll a, ll b, ll m) { return (a-b+m)%m; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m; }
ll mod_div(ll a, ll b, ll m) { return ((a % m) * bin_expo(b, m - 2, m)) % m; }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};
const ll infLL = 4e18 + 123;
const ll inf = 1e12 + 7;
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ll mx = 1e5 + 123 ; 
ll tcc = 0 ; 
ll fact[mx] , inv[mx]  ; 
ll ncr_modmPrime(ll n , ll r , ll m) {   
        fact[0] = inv[0] = 1 ; for(ll i=1;i<mx;i++) {fact[i] = mod_mul(fact[i-1],i,m)  ; }
        inv[mx-1] = bin_expo(fact[mx-1],m-2,m) ;for(ll i=mx-2;i>=1;i--) {inv[i] = mod_mul(inv[i+1],(i+1),m) ; } 
        ll up = fact[n] ; ll down = mod_mul(inv[r],inv[n-r],m) ; ll ans = mod_mul(up,down,m) ;return ans ; 
} 


// ------------------------------------------------------------------------------------------------------------


vl adj[mx] , tadj[mx] ;
ll vis[mx] , cnt = 0 ; 
stack<ll>stk ;
 
 
void dfs1(ll node) {
        vis[node] = 1 ;
        for(auto it:adj[node]) {
                if(!vis[it]) {
                        dfs1(it) ; 
                }
        } 
        stk.push(node) ; 
}
 
 
void dfs2(ll node) {
        cnt ++ ; 
        vis[node] = 0 ;
        for(auto it:tadj[node]) {
                if(vis[it]) {
                        dfs2(it) ; 
                }
        } 
}
 
void solution() {       
 
        ll n , m ; 
        cin >> n >> m ; 
        stack<ll> emptyStack;
        swap(stk, emptyStack); 
        for(ll i=0;i<=n;i++) {
                adj[i].clear() ; 
                tadj[i].clear() ; 
                vis[i] = 0 ; 
        }
        for(ll i=0;i<m;i++) {
                ll u , v ; 
                cin >> u >> v ; 
                adj[u].push_back(v) ;  
                tadj[v].push_back(u) ; 
        }
        for(ll i=1;i<=n;i++) {
                if(!vis[i]) {
                        dfs1(i) ; 
                }
        }
        vector<ll> scc ;
        while(!stk.empty()) {
                ll topnode = stk.top() ; 
                stk.pop() ; 
                if(vis[topnode]) {
                        cnt = 0 ;
                        dfs2(topnode) ;  
                        scc.push_back(topnode) ; 
                }
        }
        
}     


int main() {
        fastIO;
        // file() ;
        ll _ = 1; cin >> _;
        while (_--) solution();
        return 0 ;
}   
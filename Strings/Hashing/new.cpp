//      BISMILLAH-IR-RAHMAN-IR-RAHIM

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
        if (pow == 0) return 1;
        ll ret = bin_expo(base, pow / 2, m) % m;
        if (pow & 1) return (ret % m * ret % m * base % m) % m;
        else return (ret % m * ret % m) % m;
}
ll mod_add(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m; }
ll mod_sub(ll a, ll b, ll m) { return ((a % m) - (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m; }
ll mod_div(ll a, ll b, ll m) { return ((a % m) * bin_expo(b, m - 2, m)) % m; }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};
const ll infLL = 4e18 + 123;
const ll inf = 1e17 + 7;
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const int mx = 1e6 + 123;
const double eps = 1e-7;
const ll p = 47 ;


// forever-striver


ll n ,tc = 0 ; 
string s ; 
vector<ll> adj[mx] , v , parent(mx) , volume(mx) , vis(mx) ; 
map<ll,ll>mp ;  
ll ans = 0 ; 
ull prime[mx] ;


void dfs(ll node , ll val) {

    vis[node] = 1 ; 
    int tempcnt= 0 ; 
    for(auto u:adj[node]) {
        if(!vis[u]) {
            ll newval = (val*prime[node]) + ( s[node] - 'A' )   ; 
            dfs(u,newval) ;
            tempcnt = 0 ;  
        }
    }
    ll kv = (val*prime[node]) + ( s[node] - 'A' )   ;
    if(tempcnt==0) {
        mp[kv]++ ;  
    }
}


void solve(ll node, ll val ) {

    ll nextval = (val*prime[node]) + ( s[node] - 'A' ) ;
    if(parent[node]==node) {
        if(mp[nextval]) ans++ ; 
        return ; 
    }
    ll newpar = parent[node] ; 
    solve(parent[node],nextval) ;
}


void solution() {

    cin >> n ; 
    for(int i=1;i<=n;i++) {
        parent[i] = i ; 
        vis[i] = 0 ; 
        volume[i] = 0  ;
    } 
    mp.clear() ; 
    ans = 0 ; 
    cin >> s ; 
    for(ll i=0;i<n-1;i++) {
        ll u , v; 
        cin >> u >> v ; 
        parent[v] = u ; 
        adj[u].push_back(v) ; 
        adj[v].push_back(u) ;
        volume[v]++ ; 
        volume[u] ++  ; 
    }
    dfs(1,0) ; 
    for(auto it:mp) {
        cout << it.first << " " << it.second << endl ; 
    }
    for(int i=1;i<=n;i++) {
        if(volume[i]==1) {
            cout << i << " " ; 
            solve(i,0) ; 
        }
    }
    cout << "Case " << ++tc << ": " ; 
    cout << ans << "/" << n << endl ;  
}

int main() {
        fastIO;
        // file() ;
        prime[0] = 1 ; 
        for(int i=1;i<mx;i++) 
        {
                prime[i] = ( 1LL * prime[i-1] * p ) % mod ;  
        }
        ll _ = 1; cin >> _;
        while (_--) solution();
        return 0;
}

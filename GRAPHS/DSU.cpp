#include <bits/stdc++.h>
using namespace std ;
typedef long long ll  ;
typedef long double ld ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
using u64 = unsigned long long ;
using uint64 = unsigned long long ;
typedef vector<vi> vvi ;
typedef vector<vl> vvl ;
typedef pair<int, int> pii ;
typedef pair<ll, ll> pll ;
typedef pair<float, float> pff ;
typedef pair<double, double> pdd ;
typedef pair<ll, ll> pll ;
#define pb push_back
#define el << '\n' ;
#define all(a) (a).begin(),(a).end()
#define allr(a) (a).begin(),(a).end()
#define F first
#define S second
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0) ;
ll bin_expo(ll base, ll pow, ll m) {
    if (pow == 0) return 1;ll ret = bin_expo(base, pow / 2, m) % m ;
    if (pow & 1) return (ret % m * ret % m * base % m) % m;else return (ret % m * ret % m) % m ; }
ll mod_add(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m ; }
ll mod_sub(ll a, ll b, ll m) { return (a-b+m)%m ; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m ; }
ll mod_div(ll a, ll b, ll m) { return ((a % m) * bin_expo(b, m - 2, m)) % m ; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a ; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b) ; }
ll NEGMOD(ll a , ll m) { return ((a%m)+m)%m ; }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 4e18 + 123 ;
const ll inf = 1e12 + 7 ;
const ll mod = 1e9 + 7 ;
const ll mod2 = 998244353 ;
const ll mx = 1e5 + 10 ;
ll LOG = 21 ;
// -------------------------------------------------------------------------------------------------------


class DSU{
public: 
    vector<int> parent , rank ; 
    void Init(int n) {       // Initialize the values 
        parent.resize(n) ; 
        rank.resize(n) ; 
        for(int i=0;i<n;i++) {
            parent[i] = i ; 
        }
    }        
    int find(int v) {      // find the parent of v 
        if(v==parent[v]) return v ; 
        return parent[v] = find(parent[v]) ; 
    }
    void Union(int u , int v) {      // do union operation between u and v
        int parU = find(u) ; 
        int parV = find(v) ; 
        if(parU!=parV) {
            if(rank[parU]<rank[parV]) {
                swap(parU,parV) ; 
            }
            parent[parV] = parU ; 
            rank[parU] += rank[parV] ; 
        }
    }
    bool isConnected(int u , int v) {        // are u and v in the same group ? 
        return find(u)==find(v) ; 
    }
};


void solution(int cs) { 
    DSU dsu ; 
    dsu.Init(mx) ; 
    ll n , k ; 
    cin >> n >> k ; 
    for(int i=0;i<k;i++) {
        int u , v ; 
        cin >> u >> v ;
        if(!dsu.isConnected(u,v)) {
            cout << "Not Connected" el ; 
            dsu.Union(u,v) ;
        }      
        else {
            cout << "Connected" el ; 
        }
    }
     
}   

int main() {    
    fastIO ;
    #ifndef ONLINE_JUDGE
    file() ;
    #endif
    int cs = 1 ;
    //cin >> cs ;
    for(ll i=1;i<=cs;i++) solution(i) ;
    return 0 ;
}
    
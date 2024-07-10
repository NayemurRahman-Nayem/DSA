//      بسم الله الرحمن الرحيم
//      All praise is due to ALLAH alone



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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sa(v) sort(v.begin(), v.end())
#define sd(v) sort(v.begin(), v.end(), greater<>())
#define el << '\n'
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll bin_expo(ll base, ll pow, ll m)
{       if (pow == 0) return 1;
        ll ret = bin_expo(base, pow / 2, m) % m;
        if (pow & 1)return (ret % m * ret % m * base % m) % m;
        else return (ret % m * ret % m) % m;}
ll mod_add(ll a, ll b, ll m) { return (a % m + b % m) % m; }
ll mod_sub(ll a, ll b, ll m) { return (a % m - b % m) % m; }
ll mod_mul(ll a, ll b, ll m) { return (a % m * b % m) % m; }
ll mod_div(ll a, ll b, ll m) { return (a % m * bin_expo(b, m - 2, m)) % m; }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 1e18 ;
const ll inf = 1e17 + 7 ;
const ll mod = 1e9 + 7 ;
const int mx = 2e5 + 123 ;
const double eps = 1e-7 ;

ll n , m ;
bool possible ;  
vl topological ; 
ll vis[mx] , dis[mx] ;
vector<pair<int,int>>adj[mx] ;  


void dfs(int u)
{
        vis[u] = 1 ; 
        for(auto i:adj[u])
        { 
                int v = i.first ; 
                int w = i.second ; 
                if(!vis[v])
                {
                        dfs(v) ; 
                }
        }
        topological.pb(u) ; 
}


void topological_sort()
{ 
        topological.clear() ; 
        for(int i=1;i<=n;i++)
        {
                if(!vis[i])
                {
                        dfs(i) ; 
                }
        }
        reverse(topological.begin(),topological.end()) ; 
        possible = (topological.size()==n) ; 
}




void solution()
{
        cin >> n >> m ; 
        for(int i=1;i<=n;i++)
        {
                adj[i].clear() ; 
                vis[i]=0 ; 
                dis[i] = infLL ; 
        }
        for(int i=0;i<m;i++)
        {
                int u , v , w ; 
                cin >> u >> v >> w ; 
                adj[u].pb(make_pair(v,w)) ; 
        }
        possible = false ; 
        topological_sort() ; 
        if(possible) 
        {
                for(auto i:topological) cout << i << " " ; cout el; 
        }
        else cout << "Not Possible" el; 
}


int main()
{
        fastIO;
        // file() ;
        int _ = 1; //cin >> _ ;
        while (_--) solution();
        return 0;
}
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
#define el << '\n'
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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



int a[mx] , sgtree[mx*4] ; 
int T ; 

void build(int node , int start , int end)
{ 
        if(start==end) 
        {
                sgtree[node] = a[start]  ; 
                return ;   
        }
        int mid = (start+end) / 2 ; 
        int left = node*2 ; 
        int right = node*2 + 1 ; 
        build(left,start,mid) ; 
        build(right,mid+1,end) ; 
        sgtree[node] = sgtree[left] + sgtree[right] ; 
}


int query(int node , int start , int end , int l , int r )
{
        if(l>end or r<start) return 0 ; 
        else if(l<=start and end<=r) return sgtree[node] ; 
        int mid = (start+end) / 2 ; 
        int left = node*2 ; 
        int right = node*2 + 1 ; 
        int ret1 = query(left,start,mid,l,r) ; 
        int ret2 = query(right,mid+1,end,l,r) ; 
        return ret1 + ret2 ; 
}


void update(int node , int start , int end , int index , int newval )
{
        if(index>end or index<start) 
        {
                return ; 
        } 
        if(start==end and index==start)  
        {
                sgtree[node] = newval  ; 
                return ; 
        } 
        int mid = (start+end) / 2 ; 
        int left = node*2 ; 
        int right = node*2 + 1 ; 
        update(left,start,mid,index,newval) ; 
        update(right,mid+1,end,index,newval) ; 
        sgtree[node] = sgtree[left] + sgtree[right] ; 
}

void solution()
{       
        int n , m ; 
        cin >> n >> m ;
        for(int i=0;i<=n;i++) sgtree[i] = 0  ; 
        for(int i=1;i<=n;i++)
        {
                cin >> a[i] ; 
        } 
        build(1,1,n) ;
        
}


int main()
{
        fastIO;
        // file() ;
        int _ = 1; cin >> _;
        while (_--) solution();
        return 0;
}

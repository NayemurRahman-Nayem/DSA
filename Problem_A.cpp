//      بسم الله الرحمن الرحيم              
//      All praise is due to ALLAH alone    



#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef unsigned long long ull ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
typedef vector<vi> vvi ;
typedef vector<vl> vvl ;         
typedef pair<int, int> pii ;
typedef pair<float, float> pff ;
typedef pair<double, double> pdd ;
typedef pair<ll, ll> pll ;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ; 
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
 
 
#define sa(v) sort(v.begin(), v.end())
#define sd(v) sort(v.begin(), v.end(), greater<>())
#define el << '\n'
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
ll bin_expo(ll base ,ll pow , ll m)
{ 
        if(pow==0) return  1 ; 
        ll ret = bin_expo(base,pow/2,m) % m  ; 
        if(pow&1) return (ret%m * ret%m * base%m)%m ; 
        else return (ret%m * ret%m)%m ; 
}
ll lcm(ll a, ll b)  {  return (a * b) / __gcd(a, b);  }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 1e18 ;
const ll inf = 1e17 + 7 ;
const ll mod = 1e9+7 ;
const int mx = 2e5 +123 ;
const double eps = 1e-7 ;




ll fen[mx] , k , n ; 


void update(ll i , ll add)            
{
        while(i<=k)
        {
                fen[i] += add ; 
                i = i + (i & (-i)) ; 
        }
}


ll sum(ll i)                  
{
        ll s = 0 ; 
        while(i>0)
        {
                s += fen[i] ; 
                i = i - (i & (-i)) ; 
        }
        return s ; 
}


void solution()
{ 
        k = 0 ; 
        ll ans = 0 ;
        cin >> n ; 
        vl a(n) ; 
        map<pll,ll>mp ; 
        for(int i=0;i<n;i++)
        {
                cin >> a[i] ;
                mp[{a[i],i+1}] ;   
        }
        ll pt = 1 ; 
        for(auto &i:mp)
        {
                i.second = pt ++ ; 
        }
        for(int i=0;i<n;i++)
        {
                a[i] = mp[{a[i],i+1}] ; 
                k = max(k,a[i]) ; 
        }
        for(int i=1;i<=k;i++)
        {
                fen[i] = 0 ;  
        }
        for(int i=0;i<n;i++)
        {
                ll total = sum(k) ; 
                ll less = sum(a[i]) ; 
                ans += total - less  ; 
                update(a[i],1) ; 
        }
 
        cout << ans el; 
}


int main()
{
        fastIO ;
        // file() ;
        int _ = 1; cin >> _ ;
        while (_--) solution() ;
        return 0 ;
}
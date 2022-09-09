#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll> vl ;
typedef vector<vi> vvi ;
typedef vector<vl> vvl ;
typedef pair<int, int> pii ;
typedef pair<float, float> pff ;
typedef pair<double, double> pdd ;
typedef pair<ll, ll> pll ;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};
const ll infLL = 1e18 ;
const ll inf = 1e17 + 7 ;
const ll mod = 1e9 + 7 ;
const int mx = 1e5 + 123 ;
const double eps = 1e-7 ;
 
 
ull pHash[mx] , sHash[mx] ;
ull prime[mx] ;
const ull p = 3797 ;
ull n ;
string s ;
 
 
 
ull preHash(int x,int y)
{
        return ( pHash[y] - ( pHash[x-1]*prime[y-x+1] ) )  ; 
}
 
ull postHash(int x,int y)
{
        return ( sHash[x] - ( sHash[y+1]*prime[y-x+1] ) ) ; 
}
 
 
bool check(int diff)
{
        bool ok = false ;
        for(int i=1;i<n;i++)
        {
                ll j = i + diff - 1 ; 
                if(j>=n) break ; 
                ll a = preHash(i,j) ; 
                ll b = postHash(i,j) ; 
                if(a==b) ok = true ; 
        }
        return ok ;
}
 
 
void solution()
{
        cin >> n ;
        cin >> s ;
        s = '0'+s ;
        n = s.size() ;
        prime[0]=1 ;
        for(int i=1;i<=n;i++)
        {
                prime[i] = prime[i-1] * p ;
        }
        for(int i=1;i<n;i++)
        {
                pHash[i] = pHash[i-1]*p + s[i] ;
        }
        for(int i=n-1;i>=1;i--)
        {
                sHash[i] = sHash[i+1]*p + s[i] ; 
        }
        int ans = 1 ;
        int l = 1 , r = n ;
        while(l<=r)
        {
                int m = (l+r)/2;
		
		if(check(m))
		{
			ans = m;
			l = m+1;
		}
		else if(check(m+1))
		{
			ans = m+1;
			l = m+1;
		}
		else if(check(m-1))
		{
			ans = m-1;
			l = m+1;
		}
		else
			r = m-1;
        }
        cout << ans << endl ;
}
 
 
int main()
{
        fastIO;
        // file() ;
        int _ = 1; //cin >> _;
        while (_--) solution();
        return 0;
}

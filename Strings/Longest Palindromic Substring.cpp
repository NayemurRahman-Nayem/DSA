// Bismillahir Rahmanir Rahim


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
    if (pow == 0) return 1;ll ret = bin_expo(base, pow / 2, m) % m ;
    if (pow & 1) return (ret % m * ret % m * base % m) % m;else return (ret % m * ret % m) % m ; }
ll ncr(ll n , ll r) {ll mul = 1 ; for(ll i=1;i<=r;i++) {mul = mul * (n-i+1) ; mul = mul/i ; }return mul ; }
ll mod_add(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m ; }
ll mod_sub(ll a, ll b, ll m) { return (a-b+m)%m ; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m ; }
ll mod_div(ll a, ll b, ll m) { return ((a % m) * bin_expo(b, m - 2, m)) % m ; }
ll aModB(ll a , ll b) { if(a<0 ) { return ((a+(abs(a)/b)*b)+b)%b ; } else { return a%b; } }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b) ; }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 4e18 + 123 ;
const ll inf = 1e12 + 7 ;
const ll mod = 1e9 + 7 ;
const ll mod2 = 998244353 ;
const ll mx = 1e6 + 1 ;

// ---------------------------------------------------------------------------------------------------------------------


int N, m, SA[mx], LCP[mx];
int x[mx], y[mx], w[mx], c[mx];


inline bool cmp(const int a, const int b, const int l) { return (y[a] == y[b] && y[a + l] == y[b + l]); }

void Sort()
{
    for (int i = 0; i < m; ++i)
        w[i] = 0;
    for (int i = 0; i < N; ++i)
        ++w[x[y[i]]];
    for (int i = 0; i < m - 1; ++i)
        w[i + 1] += w[i];
    for (int i = N - 1; i >= 0; --i)
        SA[--w[x[y[i]]]] = y[i];
}


void DA(string str)
{
    ++N;
    for (int i = 0; i < N; ++i)
        x[i] = str[i], y[i] = i;
    Sort();
    for (int i, j = 1, p = 1; p < N; j <<= 1, m = p)
    {
        for (p = 0, i = N - j; i < N; i++)
            y[p++] = i;
        for (int k = 0; k < N; ++k)
            if (SA[k] >= j)
                y[p++] = SA[k] - j;
        Sort();
        for (swap(x, y), p = 1, x[SA[0]] = 0, i = 1; i < N; ++i)
            x[SA[i]] = cmp(SA[i - 1], SA[i], j) ? p - 1 : p++;
    }
    for (int i = 1; i < N; ++i)
        SA[i - 1] = SA[i];
    --N;
}


void kasaiLCP(string str) {
    for (int i = 0; i < N; ++i) {
        c[SA[i]] = i;
    }
    LCP[0] = 0;
    for (int i = 0, h = 0; i < N; ++i) {
        if (c[i] > 0) {
            int j = SA[c[i] - 1];
            while (i + h < N && j + h < N && str[i + h] == str[j + h]) {
                ++h;
            }
            LCP[c[i]] = h;
            if (h > 0) {
                --h;
            }
        }
    }
}

void suffixArray(string str) {
    m = 256;
    N = str.size() ;
    DA(str);
    kasaiLCP(str);
}

void solution(ll cs) {

    string s , t ;
    cin >> s ;
    t = s ;
    reverse(all(t)) ;
    string str = s  + t ;
    suffixArray(str) ;
    ll biglen = 0 , index = 0 ;
    for(ll i=0;i<str.size();i++) {
        if( ( (SA[i]<s.size() and SA[i-1]>=s.size() ) || (SA[i]>=s.size() and SA[i-1]<s.size() ) ) and LCP[i]>=biglen) {
            biglen = LCP[i] ;
            index = SA[i] ;
        }
    }
    cout << biglen el ;
    for(int i=index;i<index+biglen;i++) {
        cout << str[i] ;
    }
    cout el ;
}


int main() {

    fastIO  ;
    #ifndef ONLINE_JUDGE
    file() ;
    #endif
    ll cs = 1 ;
    //cin >> cs ;
    for(ll i=1;i<=cs;i++) solution(i) ;
    return   0 ;
}

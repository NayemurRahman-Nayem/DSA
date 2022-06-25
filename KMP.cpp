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
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll bin_expo(ll base, ll pow, ll m)
{       if (pow == 0) return 1;
        ll ret = bin_expo(base, pow / 2, m) % m;
        if (pow & 1)return (ret % m * ret % m * base % m) % m;
        else return (ret % m * ret % m) % m; }
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
const int mx = 3e4 + 123 ;
const double eps = 1e-7 ;


vector<int> prefix_function(string s)
{
        int n = s.size() ;
        vector<int>pi(n,0) ;
        for(int i=1;i<n;i++)
        {
                int j = pi[i-1] ;
                while(j>0 and s[i]!=s[j])
                        j = pi[j-1] ;
                if(s[i]==s[j]) j++ ;
                pi[i] = j ;
        }
        return pi ;
}
void solution()
{
        string s , t ;
        cin >> s >> t ;
        vector<int> prefix = prefix_function(t) ;
        vector<int>pos ;
        int j = 0 , i = 0 ;
        while(i<s.size())
        {
                if(s[i]==t[j])
                {
                        j++ ;
                        i++ ;
                }
                else
                {
                        if(j!=0) j = prefix[j-1] ;
                        else i++ ;
                }
                if(j==t.size())
                {
                        pos.push_back(i - t.size()) ;
                        j=0 ;
                }
        }
        for(auto it:pos) cout << it << " " ;
        cout << endl;
}
int main()
{
        fastIO;
        // file() ;
        int _ = 1; cin >> _ ;
        while (_--) solution();
        return 0;
}

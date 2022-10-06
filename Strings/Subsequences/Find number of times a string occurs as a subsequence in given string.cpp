
//      Bismillah-ir-Rahman-ir-Rahim


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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
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
ll mod_add(ll a, ll b, ll m) { return ( ( a % m ) + ( b % m ) ) % m ; }
ll mod_sub(ll a, ll b, ll m) { return ( ( a % m ) - ( b % m ) ) % m ; }
ll mod_mul(ll a, ll b, ll m) { return ( ( a % m ) * ( b % m ) ) % m ; }
ll mod_div(ll a, ll b, ll m) { return ( ( a % m ) * bin_expo(b, m - 2, m) ) % m ; }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};
const ll infLL = 1e18 ;
const ll inf = 1e17 + 7 ;
const ll mod1 = 1e9 + 7 ;
const ll mod2 = 1e9 + 9 ; 
const int mx = 1e5 + 123 ;
const double eps = 1e-7 ;




int countWays(string s, string t)
{
        int n = s.size(), m = t.size() ;
        vector<double> count(m, 0) ;
        for (int i = 0; i < n; i++)  
        {
                for (int j = m - 1; j >= 0; j--)  
                {
                        if (s[i] == t[j])
                        {
                                count[j] += (j == 0 ? 1 : count[j - 1]) ; 
                        }
                }
        }
        return (int) count[m - 1] ;
        // Time Complexity O(NxM) 
        // Space Complexity O(M) 
}

int countSubseq(string s, string t) 
{
        int n = s.size() ; 
        int m = t.size() ;
        s = '0' + s ; 
        t = '0' + t ; 
        vector<vector<double>> dp(n+1,vector<double>(m+1,0)) ; 
        for(int i=0;i<=n;i++) dp[i][0] = 1 ; 
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=m;j++)
                {
                        if(s[i]==t[j])
                        {
                                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] ; 
                        }
                        else 
                        {
                                dp[i][j] = dp[i-1][j]  ; 
                        }
                }
        }
        return (int) dp[n][m] ;    
        // time complexity O(nxm) 
        // space complexity O(nxm) 
}


void solution()
{
        string s = "abdcpacdbc", t = "abc" ;
        cout << countWays(s,t) << " " << countSubseq(s,t) << endl ; 
}


int main()
{
        fastIO;
        // file() ;
        int _ = 1; //cin >> _;
        while (_--) solution();
        return 0;
}



// Document Link : https://docs.google.com/document/d/1DMygBioM3P-cpsRnNvJrW-cPKu4EwldlkwZDVQulfQU/edit 


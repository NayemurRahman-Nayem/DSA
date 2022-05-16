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
const int mx = 5e5 +123  ;
const double eps = 1e-7 ;



ll fen[mx] , n , a[mx] , m ; 


void update(ll i , ll add)            // add new value 'add' in the ith index of the fenwick tree
{
        while(i<=n)
        {
                fen[i] += add ; 
                i = i + (i & (-i)) ; 
        }
}


ll sum(ll i)              // return sum from index 1 to index i 
{
        ll s = 0 ; 
        while(i>0)
        {
                s += fen[i] ; 
                i = i - (i & (-i)) ; 
        }
        return s ; 
}


ll rangesum(ll l , ll r)        // returns the sum between index l and r 
{
        return sum(r) - sum(l-1) ; 
}


ll binary_lifting(ll k)            // find the lower bound of k as like as binary search 
{
        ll curr = 0 , presum = 0  ; 
        for(int i=log2(n);i>=0;i--)
        {
                if( fen[curr+(1<<i)]+presum < k )
                {
                        curr = curr + (1<<i) ; 
                        presum += fen[curr] ; 
                }
        }
        return curr + 1 ; 
}


void solution()
{ 
        cin >> n >> m ;  
        for(int i=1;i<=n;i++)
        {
                cin >> a[i] ;
                update(i,a[i]) ;  
        }


}



int main()
{
        fastIO ;
        // file() ;
        int _ = 1; //cin >> _ ;
        while (_--) solution() ;
        return 0 ;
}

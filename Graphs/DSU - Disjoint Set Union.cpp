//      BISMILLAH-HIR-RAHMAN-NIR-RAHIM              
//      All praise is due to ALLAH alone    
 
 
 
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;       
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
 
 
#define el << '\n'
#define pb push_back
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
ll lcm(ll a, ll b)  {  return (a * b) / __gcd(a, b);  }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 1e18 ;
const ll inf = 10000000000000+1234 ;
const ll mod = 1000000007  ;
const int mx = 5e2 + 123 ;
 
 
ll parent[mx] ; 
ll volume[mx] ; 


ll find_parent(ll v)
{
        if(v==parent[v]) return v ; 
        return parent[v] = find_parent(parent[v]) ; 
}


void make_union(ll u , ll v)
{
        u = find_parent(u) ; 
        v = find_parent(v) ; 
        if(u!=v)
        {
                if(volume[u]<volume[v]) 
                {
                        swap(u,v) ; 
                }
                parent[v] = u ; 
                volume[u] += volume[v] ; 

        }
}
 
 
void solution()
{       
        for(int i=0;i<mx;i++)
        {
                parent[i] = i ; 
                volume[i] = 1 ; 
        }
        ll n , q ; 
        cin >> n >> q ; 
        for(int i=0;i<n;i++)
        {
                ll u , v ; 
                cin >> u >> v ;
                make_union(u,v) ; 
        }

        for(int i=0;i<q;i++)
        {
                ll u , v ; 
                cin >> u >> v ; 
                if(find_parent(u)!=find_parent(v))
                {
                        cout << "Disconnected" el;
                }
                else cout << "Connected" el ; 
        }
}
 
 
int main()
{
        fastIO ;
        //file() ;
        int _ = 1; //cin >> _ ;
        while(_--) solution() ;
        return 0 ;
}

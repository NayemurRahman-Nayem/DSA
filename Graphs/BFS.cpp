//بسم الله الرحمن الرحيم


#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;
//using u128 = __uint128_t;
#define el << '\n'
#define PI 3.141592653589793238
#define _test_ int _ ; cin >> _ ; while(_--)
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
ll gcd ( ll  a, ll b ) { return __gcd ( a, b ) ; }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ) ; }
int dx[]={0,0,+1,-1,+1,-1,-1,+1} ;
int dy[]={+1,-1,0,0,+1,-1,+1,-1} ;
///   ***   ---   |||__________LET'S BEGIN (-_^)________|||   ---   ***   ///

const ll infLL = 1e15 ;
const int inf = 1e9 ;
const int mod = 1e6+3 ;
const int mx = 1e4+123;
vector<int>adj[mx];
int lev[mx],n,m,u,v;


void bfs( int s)
{
    memset(lev,-1,sizeof(lev));
    lev[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(auto u:adj[f])
        {
            if(lev[u]==-1)
            {
                lev[u]=lev[f]+1;
                q.push(u);
            }
        }
    }

}

void _case_()
{

    for(int i=0;i<mx;i++)
        adj[i].clear();
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);
    cout << lev[n] el;
}

int main( )
{
    optimize( );
    //_test_
    _case_( ) ;
}

///////////* ________ *  N A Y E M  * ________ *///////////

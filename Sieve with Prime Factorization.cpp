
#include<bits/stdc++.h>
using namespace std ; 
typedef long long ll ; 
const int mx = 1e6+123 ; 




bitset<mx>vis ; 
vector<ll> prime ; 
void sieve()
{
        vis[1]=1; 
        for(int i=3;i*i<mx;i+=2)
        {
                if(!vis[i])
                {
                        for(int j=i*i;j<mx;j+=2*i)
                        {
                                vis[j] = 1 ;  
                        }
                }
        }
        for(int i=4;i<mx;i+=2) vis[i]=1 ; 
        prime.push_back(2) ; 
        for(int i=3;i<mx;i+=2) 
        {
                if(!vis[i]) prime.push_back(i) ;  
        }
}

vector<pair<ll,ll>> prime_factorization(ll n)
{
        vector<pair<ll,ll>>factors; 
        for(auto i:prime)
        {
                if(i*i>n) break ; 
                if(n%i==0)
                {
                        int cnt = 0 ; 
                        while(n%i==0)
                        {
                                cnt ++ ; 
                                n/=i ; 
                        }
                        factors.push_back({i,cnt}) ; 
                }
        }
        if(n!=1)
        {
                factors.push_back({n,1}) ; 
        }
        return factors ; 
}

int main()
{
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        sieve() ; 
        int tc ; 
        cin >> tc ; 
        while(tc--)
        {
                int n ; 
                cin >> n; 
                vector<pair<ll,ll>> factors = prime_factorization(n) ;
                for(auto i:factors)
                {
                        cout << i.first << " " << i.second << endl ; 
                }

        }
}

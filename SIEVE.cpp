#include<bits/stdc++.h>
using namespace std ; 
typedef long long ll ; 
const int mx = 1e5+123 ; 


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
        prime.push_back(2) ; 
        for(int i=3;i<mx;i+=2) 
        {
                if(!vis[i]) prime.push_back(i) ;  
        }
}

int main()
{
        sieve() ; 
        int n ; 
        cin >> n; 
        cout << prime[n-1] << endl ; 
}

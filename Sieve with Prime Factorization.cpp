
bitset<mx>vis;
vl prime;
void sieve()
{
    prime.push_back(2);
    for(ll i=3;i*i<=mx;i+=2)
        if(!vis[i])
            for(ll j=i*i;j<mx;j+=2*i)
                vis[j]=1;
    for(ll i=3;i<mx;i+=2)
        if(!vis[i])
            prime.push_back(i);
}

void prime_factorizarion (ll n)
{
  
    for(auto p:prime)
    {
        if(p*p>n) break;
        if(n%p==0)
        {
            int cnt=0;
            while(n%p==0)
            {
                cnt++;
                n/=p;
            }
        }
    }
    if(n!=1)
    {

    }

}


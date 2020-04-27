#include<bits/stdc++.h>
using namespace std;

using ll =long long;
const ll MAXN = 1e7+1;

bitset<MAXN> bs;

vector<ll> primes;

void sieve()
{
    bs.set();
    primes.push_back(2);
    for(ll i=3; i<MAXN; i+=2)
    {
        if(bs[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<MAXN; j+=i<<1)
            {
                bs[j]=0;
            }
        }
    }
}


bool isprime(ll n)
{
    for(ll i=0; primes[i]*primes[i]<=n; i++)
    {
        if(n%primes[i]==0)
            return 0;
    }
    return 1;
}

void solve()
{

    ll n,sum=0;
    cin >> n;
    n--;

    if(!(n&1) && n!=2)
        n--;

    if(n<MAXN)
    {
        for(ll i=n;; i-=2)
        {
            if(bs[i])
            {
                cout<<i<<'\n';
                return;
            }
        }
    }
    for(ll i=n;; i-=2)
    {
        if(isprime(i))
        {
            cout<<i<<'\n';
            return;
        }
    }

}

int main()
{
    sieve();
    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }


}

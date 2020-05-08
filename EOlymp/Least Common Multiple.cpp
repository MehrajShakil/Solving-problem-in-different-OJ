#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e7;

bitset<MAXN+1> bs;
vector<ll> primes;

void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;

    for(ll i=4; i<=MAXN; i+=2)
        bs[i]=0;

    primes.push_back(2);
    for(ll i=3; i<=MAXN; i+=2)
    {
        if(bs[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=MAXN; j+=i<<1)
                bs[j]=0;
        }
    }

}

void Factor(ll x, map<ll,ll> &mp)
{
    for(ll i=0; i<primes.size() and primes[i]*primes[i]<=x; i++)
    {
        ll p= primes[i],freq=0;
        while(x%p==0)
        {
            x/=p;
            freq++;
        }
        if(freq>0)
            mp[p]=max(mp[p],freq);
    }
    if(x>1)
    {
        mp[x] = max(mp[x], 1LL);
    }

}

ll multiple(ll base, ll power)
{
    ll mul=1;
    for(ll i=1; i<=power; i++)
    {
        mul*=base;
    }

    return mul;
}

void solve()
{
    ll n,ans=1;
    cin >> n;
    ll arr[n];
    for(ll i=0; i<n; i++)
        cin >> arr[i];

    map<ll,ll>mp;

    for(ll i=0; i<n; i++)
    {
        Factor(arr[i],mp);
    }

    for(auto it : mp)
    {
        //  cout <<  it.first << " " << it.second << '\n';
        ans*=multiple(it.first,it.second);
    }
    cout << ans << '\n';
}


int main()
{
    sieve();
    ll t;
    cin >> t;
    while(t--)
    {
        solve() ;
    }
}

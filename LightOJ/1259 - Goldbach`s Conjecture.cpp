

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 1e7;
bitset<MAXN+1> bs;
vector<ll> primes;

void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;
    primes.push_back(2);
    for(ll i=4; i<=MAXN; i+=2)
        bs[i]=0;

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

ll Way(ll n)
{
    ll upay=0;
    for(ll i=0; i<primes.size() and 2*primes[i]<=n ; i++)
    {
        ll p=primes[i];
        if(bs[n-p] ){
            upay++;
        }
    }

    return upay;
}


int main()
{
    sieve();

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t,tc=0;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;

        cout <<"Case " << ++tc << ": " << Way(n) << '\n';
    }
}

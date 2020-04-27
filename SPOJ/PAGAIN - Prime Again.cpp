#include<bits/stdc++.h>
using namespace std;

using ll =long long;
const ll MAXN = 1e7+1;

bitset<MAXN> bs;

vector<ll> primes;
/// sieve algorithm diye 10^7 porjonto prime number ber kore niyechi.
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

/// ekta number check kortechi seti prime kina.
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
    if(n==3)
    {
        cout<<2<<'\n';
        return;
    }

    if(n&1)
        n-=2; /// n odd hole 2 minus korechi.
    else
        n--;    /// n even hole 1 minus korechi

    if(n<MAXN)   /// ei khane check korechi n ki 10^7 er vitore kina tahole amra precalculate sive diye answer pacci.
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

    for(ll i=n;; i-=2)  /// n er value 2 kore komacci karon akta odd theke 2 minus korle tar nearly smallest odd ta pawa jabe.

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

// C++ program to implement bitwise Sieve
// of Eratosthenes.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXN= 1e7;

bitset<MAXN+1> bs;
vector<ll> primes;

void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;
    for(ll  i=2; i<=MAXN; i++)
    {
        if(bs[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=MAXN; j+=i<<1)
            {
                bs[j]=0;
            }
        }
    }


}

ll Factor(ll n)
{
    ll tot=0,ans=1;

    for(ll i=0; i<primes.size() and primes[i]*primes[i]<=n; i++)
    {
        tot=0;
        while(n%primes[i]==0)
        {
            n/=primes[i];
            tot++;
        }
       ans*=(2*tot+1);
    }
    if(n>1)
        ans*=3;

    return ans/2+1;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    ll t,tc=0;
    cin >> t;
    while(t--)
    {
        ll n,ans=1,tot=0;
        cin >> n;
        cout << "Case " << ++tc << ": " << Factor(n) << '\n';
    }

}

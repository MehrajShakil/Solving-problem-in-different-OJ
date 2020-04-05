
#include<bits/stdc++.h>
using namespace std;
using ll =  long long;
#define ios    ios::sync_with_stdio(0);cin.tie(0);

bitset<10000001> bs;
vector<bool> visit;
vector<ll> primes;
void sieve()
{
    bs.set();
    for(ll i=2; i<=10000000; i+=2)
    {
        bs[i]=0;
    }
    bs[0]=bs[1]=1;
    primes.push_back(2);
    for(ll i=3; i<=10000000; i+=2)
    {
        if(bs[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=10000000; j+=(i+i))
            {
                bs[j]=0;
            }
        }
    }
}

ll solve(ll n)
{
    ll ans=1;
    ll x= sqrt(n);
    for(ll i=0 ; i<primes.size() && primes[i]<=x ; i++)
    {

        ll prod=1;
        if(n < primes[i])
        {
            break;
        }
        while((n%primes[i])==0)
        {
            n/=primes[i];
            ++prod;
        }
        ans*=prod;
    }
    if(n>1)
    {
        ans*=2;
    }
    ans--;

    return ans;
}


int main()
{
    //ios
    sieve();
    ll t,tc=0;
    scanf("%lld",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        printf("Case %lld: %lld\n",++tc,solve(n));
    }

}

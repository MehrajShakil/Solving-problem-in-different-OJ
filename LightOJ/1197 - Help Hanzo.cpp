#include<bits/stdc++.h>
using namespace std;

using ll =long long;
const ll MAXN = 1e5+1;

vector<ll> primes;
vector<bool> marked,marksegment;

ll rslt1[MAXN];
ll rslt2[MAXN];

void sieve()
{
    int n=1e5;
    marked.assign(n+1,false);
    ll sqrtn = sqrt(n);
    for(ll i=3; i<=sqrtn; i+=2)
    {
        if(!marked[i])
        {

            for(ll j=i; j<=n; j+=(i<<1))  // i<<1 == i*2 , i multiply there with 2 because we know odd + odd == even . and odd + 2*odd (odd+odd)==odd
            {
                marked[j]=true;
            }
            marked[i]=false;
        }
    }

    if(n>=2)
        primes.push_back(2);

    for(ll i=3; i<=n; i+=2)
    {
        if(!marked[i])
        {
            primes.push_back(i);
        }
    }
}

ll PrimeInRange(ll low, ll high)
{
    ll limit = floor(sqrt(high))+1,cnt=0;

    ll n= high-low+1;
    marksegment.assign(n+1,false);

    for(ll i=0; i<primes.size(); i++)
    {

        ll lowlimit = floor(low/primes[i])*primes[i];

        if(lowlimit<low )
        {
            lowlimit+=primes[i];
        }
        if(lowlimit==primes[i])
        {
            lowlimit+=primes[i];
        }
        for(ll j=lowlimit; j<=high; j+=primes[i])
        {
            marksegment[j-low]=true;
        }
    }

    for(ll i=low; i<=high; i++)
    {
        if(!marksegment[i-low])
        {
            if(i==1)
                continue;
            cnt++;
        }
    }
    return cnt;
}



int main()
{

    sieve();
    ll t,a,b,tc=0;

    cin >> t;
    while(t--){
    cin >> a >> b;
    cout<<"Case "<<++tc<<": "<<PrimeInRange(a,b)<<'\n';
    }




}

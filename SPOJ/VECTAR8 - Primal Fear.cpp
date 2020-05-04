
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;

using ll =long long;
const ll MAXN = 1e6;


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
            for(ll j =i*i; j<=MAXN; j+=i<<1)
            {
                bs[j]=0;
            }
        }
    }
}

int digcount(ll num)
{
    int dig=0;
    while(num > 0)
    {
        if(num%10 == 0)
            return 0;
        dig++;
        num /= 10;
    }
    return dig;
}

ll mul(ll n)
{

    int i=1;
    ll tot=1;

    while(i<=n)
    {
        tot*=10;
        i++;
    }
    return tot;
}

int main()
{
    sieve();
    vector<ll> v(MAXN+1);
    v[0]=v[1]=0;
    for(ll i=2; i<=MAXN ; i++)
    {
        v[i]=v[i-1];
        if(bs[i])
        {
            ll x =i;
            ll digit = digcount(x);
            if(digit==0){
               continue;
            }
            ll tot = mul(digit);
            bool flag=true;
            while(x>0)
            {
                x%=tot;
                if(x!=0 and !bs[x])
                {
                    flag=false;
                    break;
                }
                tot/=10;
            }
            if(flag)
                v[i]++;
        }

    }

    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        cout << v[n] << '\n';
    }
}

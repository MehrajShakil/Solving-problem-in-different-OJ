

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>inline bool read(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')
            sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

const ll MAXN = 1e7;
/*
ll computeFirstKdigit(ll base,ll power, ll k)
{


    let , log10(prod) = n*log10(n).

    n = 1250
    d = 1250
    log10(prod) = 3871.137516 = 3871 + 0.137516
          prod  = 10^3871 * 10^0.137516   // here 10^2871 doesn't contribute in our digit. It only shift decimal point.
    so, 10^0.137516 = 1.37251.

    we need first k digit so, we take digits = pow(10,k-1)

    and return 1.37251 *digits.


    long double prod = power*log10(base*1.0);
    prod-=floor(prod);
    prod = pow(10,prod);
    return prod*pow(10,k-1);
}
*/
ll BigMod( ll base, ll power, ll mod )
{
    ll ans = 1 ;
    while(power)
    {
        if( power & 1 )
            ans = ( ans * base ) % mod ;
        base = ( base * base ) % mod ;
        power /= 2 ;
    }
    return ans ;
}

int main()
{
    //ios::sync_with_stdio(0);
    // cin.tie(0);
    //cout.tie(0);

    int t,tc=0;
    cin >> t;
    while(t--)
    {
        ll n,k;
        read(n);
        read(k);
        long double prod = k*log10(n*1.0);
        prod-=floor(prod);
        prod = pow(10,prod);
        prod*=100;
        printf("Case %d: %03d %03d\n",++tc,(int)prod,BigMod(n%1000,k,1000));
    }
}

// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

/// Author : Md Mehraj Hossain

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp> //order_of_key return number of elements less than x, find_by_order return index (pointer use kora lgbe)

using namespace std;
using namespace __gnu_pbds;

#define ull    unsigned long long
#define ll     long long
#define ios    ios::sync_with_stdio(0);cin.tie(0);
#define ses    "\n"
#define all(x) (x).begin(), (x).end()
//#define INF   ((int)2e18)
#define ii pair<ll, ll>

string digit="0123456789";
string small="abcdefghijklmnopqrstuvwxyz";
string capital="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

const ll MAXN=1e5;
const ll MOD = 1e9+7;

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)
        return 1;
    if(e%2==0)
    {
        ll t=bigmod(p,e/2,M);
        return (T)((t*t)%M);
    }
    return (T)((ll)bigmod(p,e-1,M)*(ll)p)%M;
}

template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);   // when M is prime;
}

typedef tree< ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

/// Fast read.
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

//***********************************************  The END **********************************************************************************************************************************

/////////////////////////////////////////////////////////////////////////////
bitset<MAXN+1> bs;
vector<ll> primes;

void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;

    for(ll i=4; i<=MAXN; i+=2)
    {
        bs[i]=0;
    }
    primes.push_back(2);

    for(ll i=3; i<=MAXN; i+=2)
    {
        if(bs[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=MAXN; j+=(i<<1))
                bs[j]=0;
        }
    }
}

map<ll,ll>  Factor(ll n,ll m)
{
    map<ll,ll> mp;
    for(ll i=0; i<primes.size() and primes[i]*primes[i]<=n; i++)
    {
        ll p=primes[i];
        while(n%p==0)
        {
            n/=p;
            mp[p]=1;
        }
    }
    if(n>1)
    {
        mp[n]=1;
    }
    for(ll i=0; i<primes.size() and primes[i]*primes[i]<=m; i++)
    {
        ll p=primes[i];
        while(m%p==0)
        {
            m/=p;
            mp[p]=1;
        }
    }
    if(m>1)
    {
        mp[m]=1;
    }
    return mp;
}




void solve(ll n)
{
    ll a,b,now=0,ans=1;
    map<ll,ll> common;
    while(n--)
    {
        read(a);
        read(b);
        map<ll,ll> com ;
        if(!now)
        {
            now=1;
            common = Factor(a,b);
            continue;
        }

        for(auto it : common)
        {
            if(a%it.first==0 || b%it.first==0)
                com[it.first]=1;
        }
        common=com;
    }
    auto it = common.begin();
    if(it!=common.end())
    {
        cout << it->first ;
    }
    else
        cout<< -1;
}

////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main()
{
    // ios
    sieve();
    ll n;
    read(n);
    solve(n);
}




/*



  Alhamdulillah
*/


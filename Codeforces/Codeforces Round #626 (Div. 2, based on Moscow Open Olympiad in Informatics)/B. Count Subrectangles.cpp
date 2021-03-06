///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME
///   ALLAH save us from COVID-19.Amin.

///   █▀█─█──█──█▀█─█─█
///   █▄█─█──█──█▄█─█▄█
///   █─█─█▄─█▄─█─█─█─█

///   كُلُّ نَفْسٍ ذَآئِقَةُ الْمَوْت
///   Every soul shall taste death.


///   Author : Md Mehraj Hossain
///   Tag :   deque

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp> //order_of_key return number of elements less than x, find_by_order return index (pointer use kora lgbe)

using namespace std;
using namespace __gnu_pbds;

#define ull      unsigned long long
#define ll       long long
#define ld       long double
#define pb       push_back
#define MOHAMMAD ios::sync_with_stdio(0);cin.tie(0);
#define ses      "\n"
#define all(x)   (x).begin(), (x).end()
#define pi       2*acos(0.0)
#define AE       cout << fixed << setprecision(10);

string digit="0123456789";
string small="abcdefghijklmnopqrstuvwxyz";
string capital="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

const ll MAXN=1e7+1;
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



////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main()
{

     MOHAMMAD


    ll n, m, k, subrec = 0;
    cin >> n >> m >> k;

    ll a[n+1];
    ll b[m+1];

    for ( ll i = 1 ; i<=n ; ++i )
        cin >> a[i];
    for ( ll j = 1 ; j<=m ; ++j )
        cin >> b[j];

    ll pa[n+1] = { 0 }, pb[m+1] = { 0 };

    for ( ll i = 1 ; i<=n ; ++i )
    {
        pa[i] = pa[i-1] + a[i];
    }
    for ( ll i = 1 ; i<=m ; ++i )
    {
        pb[i] = pb[i-1] + b[i];
    }


    vector< pair < ll,ll > > div;

    for ( ll i = 1 ; i*i<=k ; ++i )
    {
        if(k%i==0)
        {
            ll d1 = i;
            ll d2 = k/i;

            if(d1==d2)
                div.pb({d1,d2});
            else
            {
                div.pb({d1,d2});
                div.pb({d2,d1});
            }
        }
    }

    for ( auto it : div )
    {
        ll d1 = it.first;
        ll d2 = it.second;
       // cout << d1 << " " << d2 << ses;
        ll r1 = 1, r2 = d1;
        ll c1 = 1, c2 = d2;
        ll r = 0 , c = 0;
        for (  ; r2<=n ; r1++ , r2++ ){
             if(pa[r2]-pa[r1-1]==d1) r++;
        }
        for (  ; c2<=m ; c1++ , c2++ ){
            if(pb[c2]-pb[c1-1]==d2) c++;
        }
        subrec+=(r*c);
    }
    cout << subrec << '\n';
}

/*




  Alhamdulillah
*/


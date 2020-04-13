
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


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

const int N=1e6+5;
const ll M=1e18;
const ll MOD = 1000000007;

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

struct Edge
{
    int u, vv;
    bool operator<(Edge const& other)
    {
        return vv > other.vv;
    }
}; // eta joss jinis.krsukal er jnno and sort 1 out of 3 or more er jnno better


//***********************************************  The END **********************************************************************************************************************************


/////////////////////////////////////////////////////////////////////////////

/// 6 11
/// 45 1 10 12 11 7

////////////////////////////////////////////////////////////////////////////
//main function is here.........
int main()
{
    ios
    ll n,k;
    cin >> n >>k;
    ll arr[n];

    for(ll i=0; i<n; i++)
        cin >> arr[i];
    vector<ll> Digit[11];
    ll power[11];
    power[0]=1;
    ll len[n];
    for(ll i=1; i<11; i++)
    {
        power[i] = (power[i-1]*10)%k;
    }

    for(ll i=0; i<n; i++)
    {
        len[i]=log10(arr[i])+1;
        Digit[(ll)log10(arr[i])+1].push_back(arr[i]%k);
    }
    ll ans=0;
    for(ll i=0; i<11; i++)
    {
        sort(Digit[i].begin(),Digit[i].end());
    }
    for(ll i=0; i<n; i++)
    {
        for(ll j=1; j<11; j++)
        {
            ll rem = (arr[i]*(power[j]%k))%k;
            ll xrem = (k-rem)%k;

            auto r = upper_bound(Digit[j].begin(), Digit[j].end(), xrem);
            auto l = lower_bound(Digit[j].begin(),  Digit[j].end(), xrem);
            ans+=(r-l);
            if (len[i] == j && (rem + arr[i] % k) % k == 0) /// its gives result for him because we know i!=j.
                --ans;
        }
    }
    cout<<ans;
}
/*

*/


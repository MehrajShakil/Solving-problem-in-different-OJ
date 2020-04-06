

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
ll Compute_five(ll n)
{
    ll ans=0;
    for(ll i =5; n/i>=1; i*=5)
    {
        ans+=(n/i);
    }
    return ans;
}

void factor(ll n,ll &two, ll &five)
{
    ll nn =n;
    while(!(n%2))
    {
        n/=2;
        two++;
    }
    while(!(nn%5))
    {
        nn/=5;
        five++;
    }
}

ll compute_two(ll n )
{
    ll ans=0;
    for(ll i=2; n/i>=1; i*=2)
    {
        ans+=(n/i);
    }
    return ans;
}
////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main()
{
    // ios
    ll t,tc=0;
    cin>>t;
    while(t--)
    {
        ll n,r,p,q;
        cin>>n>>r>>p>>q;
        ll twon=0,fiven=0,twor=0,fiver=0,twonr=0,fivenr=0,twof=0,fivef=0,two=0,five=0;
        twon = compute_two(n);
        twor = compute_two(r);
        twonr = compute_two(n-r);

        fiven = Compute_five(n);
        fiver = Compute_five(r);
        fivenr = Compute_five((n-r));
        twof=(twon-twor-twonr);
        fivef=(fiven-fiver-fivenr);
        factor(p,two,five);
        two*=q;
        five*=q;
        twof+=two;
        fivef+=five;

        cout<<"Case "<<++tc<<": "<<min(twof,fivef)<<ses;
    }
}

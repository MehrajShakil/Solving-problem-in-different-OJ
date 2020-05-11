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

const ll MAXN=1e18;
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

ll mul(ll p,ll e)
{
    ll pp=p;
    for(ll i=1; i<e; i++)
    {
        p*=pp;
    }

    return p;
}

void solve(ll arr[], ll n)
{
    ll tot=1,cnt=0;
    for(ll i=0; i<n; i+=2)
    {
        tot*=mul(arr[i],arr[i+1]);
    }
    ll freq=0;
    tot--;
    vector<pair<ll,ll> > v;
    while(tot%2==0)
    {
        freq++;
        tot/=2;
    }
    if(freq>0)
        v.push_back({2,freq});
    for(ll i=3; i*i<=tot; i+=2)
    {
        freq=0;
        while(tot%i==0)
        {
            tot/=i;
            freq++;
        }
        if(freq>0)
            v.push_back({i,freq});
    }
    if(tot>1)
    {
        v.push_back({tot,1});
    }
    sort(all(v));
    reverse(all(v));

    for(auto it : v)
    {
        if(cnt>0)
            cout << " " << it.first << " " <<it.second;
        else
            cout << it.first << " " <<it.second;
        cnt++;
    }
    cout<< '\n';
}
////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main()
{
    //ios
    while(1)
    {
        string s;
        getline(cin,s);
        stringstream ss(s);
        ll i=0;
        ll arr[100000];
        while(ss>>arr[i])
            i++;
        if(arr[0]==0)
            break;
        solve(arr,i);
    }
}




/*



  Alhamdulillah
*/


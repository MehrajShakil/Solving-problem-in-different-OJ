
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

// █▀█─█──█──█▀█─█─█
// █▄█─█──█──█▄█─█▄█
// █─█─█▄─█▄─█─█─█─█


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
/*
  7
  1   2
  2   3
  2   4
  4   5
  4   6
  5   7

*/
/////////////////////////////////////////////////////////////////////////////
vector<vector<ll> > adj;
vector<ll> dis,totalchild;

void dfs(ll src, ll parent)
{
    dis[src]=dis[parent]+1;
    totalchild[src]=1;
    for(auto u : adj[src])
    {
        if(u!=parent)
        {
            dfs(u,src);
            totalchild[src]+=totalchild[u];
        }
    }

}

////////////////////////////////////////////////////////////////////////////
//main function is here.........
int main()
{
    ios
    ll n,k,ans=0,mx=0;
    cin>>n>>k;
    adj.resize(n+1);
    dis.resize(n+1);
    totalchild.resize(n+1);
    for(ll i=1; i<n; i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dis[0]=0;
    dfs(1,0);
    multiset<ll> s;

    for(ll i=1; i<=n; i++)
    {
        // cout<<dis[i]<<" "<<totalchild[i]<<ses;
        s.insert(-(dis[i]-totalchild[i]));
    }
    for(auto it : s)
    {
        mx = it;
        mx*=(-1LL);
        ans+=mx;
        k--;
        if(k==0)
            break;
    }
    cout<<ans;
}
/*

*/


///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME
///   ALLAH save us from COVID-19.Amin.

///   Every soul shall taste death.

///   Tag ::

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

///  order_of_key return number of elements less than x.
///  find_by_order return index.

using namespace std;
using namespace __gnu_pbds;


#define MOHAMMAD  ios::sync_with_stdio(0);cin.tie(0);
#define all(x)    (x).begin(), (x).end()
#define AE        cout << fixed << setprecision(10);

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

using ll = long long;
const ll MOD = 1e9 + 7;

typedef tree< int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

//debug
template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}
//#else
//#define dbg(args...)

/// Modular arithmetic
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

//***********************************************  The END **********************************************************************************************************************************
const ll N = 1e6;
const ll INF = 1e15;

vector < ll > e[N+1] , v;
bool visit[N+1];
ll low[N+1] , tin[N+1] , w[N+1] , c[N+1];
ll mx = 0 , ans = -1 , timer = 0 ,  sum = 0;


void dfs ( ll node , ll par = -1 ){

ll temp = 0;
c[node] = w[node];

visit[node] = 1;
tin[node] = low[node] = timer++;
ll cut = 0 , children = 0;
bool articulationPoint = false;
for ( auto child : e[node] ){
     if(  child==par ) continue;

     if ( visit[child] ){
          /// back edge.
          low[node] = min ( low[node] , tin[child] );
     }
     else{
         children++;
         dfs ( child , node );
         c[node]+=c[child];
         low[node] = min ( low[node] , low[child] );
         if ( par!=-1 and low[child]>=tin[node] ){
             /// articulation point.
             articulationPoint = true;
             cut+=c[child];
             temp^=c[child]; /// They are individual cc.
         }
     }

}

if ( ( par!=-1 and articulationPoint ) or ( par==-1 and children>1 ) ){
    ll cur = sum - cut - w[node];
    if(cur)temp^=cur;
    ans = max ( ans , temp );
}
}


int main()
{

   MOHAMMAD
   ll node , edge , u , v ;
   cin >> node >> edge;

   for ( ll i = 1 ; i<=node ; ++i ){
        cin >> w[i];
        sum+=w[i];
   }


   while ( edge-- ){
          cin >> u >> v;
          e[u].push_back( v );
          e[v].push_back( u );
   }

   for ( ll i = 1 ; i<=node ; ++i ){
          if ( visit[i] )continue;
          dfs ( i );
   }

   cout << ans << "\n";

}


/*

9 11
0 1
1 2
1 3
2 4
3 4
3 5
5 7
5 6
6 7
7 8
7 9





  Alhamdulillah
*/

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

/// debug
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
inline ll modInverse(ll a)   { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

//***********************************************  The END **********************************************************************************************************************************
const ll N = 400;
const ll INF = 1e18;
const ll limit = (1LL<<64) - 1;

vector < ll > e[N+1] , res;
ll order[N+1] , to;
ll degree[N+1],grid[N+1][N+1];
bool ans = true;
bool visit[N+1];

bool dfs ( ll node ){

    visit[node] = 1;
    if ( node==to ) return true;
    for ( auto child : e[node] ){
         if ( visit[child] == 0 ){
             res.push_back(child);
             grid[node][child]++;
             if(dfs ( child)) return 1;
             visit[child] = 0;
         }
    }
    for ( auto child : e[node] ){
         if ( visit[child] == 0 ){
            grid[node][child]--;
            visit[child] = 1;
         }
    }
    
    res.pop_back();
    return false;
}

int main()
{
   /// MOHAMMAD

   ll node , edge , u , v;
   cin >> node;
   edge = node - 1;

   while ( edge-- ){
        cin >> u >> v;
        e[u].push_back ( v );
        e[v].push_back ( u );
        degree[u]++;
        degree[v]++;
   }

   ll leaf = 0;
   for ( ll i = 2 ; i<=node ; ++i ){
        if ( degree[i]==1 ) leaf++;
   }
   ll now = 1;
   res.push_back(1);
   
   ///dbg ( leaf );
   
   for ( ll i = 1 ; i<=leaf+1 ; ++i )
   {
                if(i<=leaf) cin >> order[i];
                else order[i] = 1;
                 to = order[i];
                 dfs ( now );
                 now = order[i];
                 ///  cout << now << " \n";
                 ///  for ( auto it : res ) cout << it << " ";
                /// cout << "\n";
                 memset ( visit , 0 , sizeof visit );
   }

   map < pair < ll , ll > , ll > mp;

   for ( ll i = 1 ; i<res.size() ; ++i ){
        ll u = res[i-1];
        ll v = res[i];
        mp[ { u , v } ]++;
        mp[ { v , u } ]++;
      ///  cout << res[i] << " ";
        if ( mp [ { u , v } ]>2 or mp [ { v , u } ]>2 ){
                ans = 0;
             ///   dbg ( u , v );

        }
   }
   if ( !ans ) cout << -1;
   else{
                for ( auto it : res ) cout << it << " ";
   }








}


/*





  Alhamdulillah
*/

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
const ll N = 1000;
const ll INF = 1e15;

string grid[N+1];
bool visit[N+1][N+1] , ok=false;
ll n , flood = 0 , danger = 0;

void dfs ( ll x , ll y ){

if ( x<0 or x>=n or y<0 or y>=n or grid[x][y]!='#' or visit[x][y] ) return;
visit[x][y] = 1;
for ( ll i = 0 ; i<8 ; ++i ){
     ll xx = x + dx8[i];
     ll yy = y + dy8[i];
     dfs ( xx , yy );
}
return;
}


void Flood_fill ( ll x , ll y ){

if ( x<0 or x>=n or y<0 or y>=n or grid[x][y]!='*' or visit[x][y] ) return;
visit[x][y] = 1;
for ( ll i = 0 ; i<4 ; ++i ){
     ll xx = x + dx4[i];
     ll yy = y + dy4[i];
     Flood_fill ( xx , yy );
}

for ( ll i = 0 ; i<8 ; ++i ){
     ll xx = x + dx8[i];
     ll yy = y + dy8[i];
     if ( xx<0 or xx>=n or yy<0 or yy>=n ) continue;

     if ( grid[xx][yy]=='#') ok = true;
}

return;
}

int main()
{

  //MOHAMMAD

  ll t , tc = 0;
  cin >> t;
  while ( t-- ){

        cin >> n;

        for ( ll i = 0 ; i<n ; ++i ){
          cin >> grid[i];
        }
        memset ( visit , 0 , sizeof visit );
        danger = flood = 0;

        for ( ll i = 0 ; i<n ; ++i ){
           for ( ll j = 0 ; j<n ; ++j ) {
               if ( visit[i][j] == 0 and grid[i][j]=='#' ){
               flood++;
               dfs ( i , j );
               }
           }
        }

        memset ( visit , 0 , sizeof visit );

        for ( ll i = 0 ; i<n ; ++i ){
           for ( ll j = 0 ; j<n ; ++j ) {
               if ( visit[i][j] == 0 and  grid[i][j]=='*' ){
                  ok = false;
                  Flood_fill ( i , j );
                  if ( ok ) danger++;
               }
           }
        }

        cout << "Case " << ++tc << ": " << flood << " " << danger << '\n';
  }


}


/*







  Alhamdulillah
*/

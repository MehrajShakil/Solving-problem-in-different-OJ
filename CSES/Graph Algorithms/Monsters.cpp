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
#define AE        cout << fixed << setprecision(2);

/// faster.
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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
const ll N = 1e3;
const ll INF = 1e15;
const ll limit = (1LL<<64) - 1;

string ans ="UDLR";
vector < char > path;
char grid[N+1][N+1];
bool ff = 0;
ll n , m , sx , sy , ex , ey ;
ll depa[N+1][N+1] , depmonster[N+1][N+1];
bool visit[N+1][N+1];
map < pair < ll , ll > , pair < ll , ll >  > parent;
queue < pair < ll , ll > > qq;

ll mn = INF;

void bfs1 ( ){

  while ( qq.size() ) {
       ll x = qq.front().first;
       ll y = qq.front().second;
       qq.pop();

       for ( ll k = 0 ; k<4 ; k++ ){
           ll xx = x + dx4[k];
           ll yy = y + dy4[k];

           if ( xx<0 or xx>=n or yy<0 or yy>=m or grid[xx][yy]=='#' or grid[xx][yy]=='A' ) continue;
           if ( ( depmonster[x][y] + 1 ) < depmonster[xx][yy] ){
               qq.push( { xx , yy } );
               depmonster[xx][yy] = depmonster[x][y] + 1;
           }
       }
  }
}

void bfs ( ll x , ll y , ll f ){
  queue < pair < ll , ll > > q;
  q.push( { x , y } );
  if ( f == 1) depa[x][y] = 0;
///  if ( f == 0 ) depb[x][y] = 0;

  while ( q.size() ) {
       x = q.front().first;
       y = q.front().second;
     //  if ( f == 2 ) visit[x][y] = 1;
       q.pop();
      // if ( ( f==1 or f==2 ) and grid[x][y] == 'B' ) return;
      // if ( f==0 and grid[x][y] == 'A' ) return;
       ll corner = 0;
       for ( ll k = 0 ; k<4 ; k++ ){
           ll xx = x + dx4[k];
           ll yy = y + dy4[k];
           if ( xx>=0 and xx<n and yy>=0 and yy<m ) corner++;
           if ( f==2 and visit[xx][yy] ) continue;
           if ( xx<0 or xx>=n or yy<0 or yy>=m or grid[xx][yy]=='#' or grid[xx][yy]=='M' ) continue;
           if ( f==1 and  ( depa[x][y] + 1 ) < depa[xx][yy] ){
               q.push( { xx , yy } );
               depa[xx][yy] = depa[x][y] + 1;
               parent[ { xx , yy } ] = { x , y };
           }
       }
      // dbg ( x , y , corner );
       if ( corner != 4  and depa[x][y]<depmonster[x][y] ) {
          if ( mn>depa[x][y] ){
              mn = depa[x][y];
              ex = x;
              ey = y;
          }
       }
  }
}

int main()
{

  MOHAMMAD
  cin >> n >> m;

  for ( ll i = 0 ; i < n ; i++ ){
     for ( ll j = 0 ; j < m ; j++ ){
         cin >> grid[i][j];
         if ( grid[i][j] == 'A' ) sx = i , sy = j;
         depa[i][j] = depmonster[i][j] = INF;
     }
  }

  for ( ll i = 0 ; i < n ; i++ ){
     for ( ll j = 0 ; j < m ; j++ ){
         if ( grid[i][j] == 'M' ) {
             qq.push( { i , j } );
             depmonster[i][j] = 0;
         }
     }
  }
  bfs1 ( );
  bfs ( sx , sy , 1 );
  //if ( ff == 0 ) {
 //      cout << "NO\n";
  //     return 0;
 // }
 // dbg ( depa[ex][ey] );
 // bfs ( ex , ey , 0 );
 // dbg ( depb[sx][sy] );
  //bfs ( sx , sy , 2 );
ll cur = depa[ex][ey];
if ( cur==0 ){
    cout << "YES\n0";
    return 0;

}
if ( cur==INF ) cur = 0;

while ( cur-- ){
    ll cx = parent[ { ex , ey } ].first;
    ll cy = parent[ { ex , ey } ].second;
    for ( ll k = 0 ; k<4 ; ++k ){
         ll xx = dx4[k] + ex;
         ll yy = dy4[k] + ey;
         if ( xx==cx and yy==cy ){
            path.push_back( ans[k] );
            break;
         }
    }
    ex = cx;
    ey = cy;
}
reverse ( all ( path ) );

if ( path.size() ){
    cout << "YES\n";
    cout << path.size() << "\n";
    for ( auto c : path ) cout << c;
}
else{
      cout << "NO\n";
}



}


/*

Explanation:



TODO :

  Alhamdulillah
*/

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

ll row , col , paint[50][50] , Size[10000] ={ 0 } , color = 0 , len = 0 , level[50][50] , ans = INF;
bool visit[50][50];
char grid[50][50];

void Flood_fill ( ll x , ll y , char root ){
 if ( x<0 or x>=row or y<0 or y>=col or grid[x][y]!=root or visit[x][y] ) return;
 paint[x][y] = color;
 visit[x][y] = 1;
 len++;
 for ( ll i = 0 ; i<8 ; ++i ){
     ll xx = x + dx8[i];
     ll yy = y + dy8[i];
     Flood_fill ( xx , yy , root );
 }
 return;
}

void bfs ( ll sx , ll sy ){

queue < pair < ll , ll > > q;

q.push( { sx , sy } );
visit[sx][sy] = 1;
level[sx][sy] = 0;

while( q.size() ){

   ll x = q.front().first;
   ll y = q.front().second;
   q.pop();

   for ( ll i = 0 ; i<8 ; ++i ){
     ll xx = x + dx8[i];
     ll yy = y + dy8[i];
     if ( xx<0 or xx>=row or yy<0 or yy>=col or paint[sx][sy] == paint[xx][yy] ) continue;
     if ( visit[xx][yy]==0 ){
     visit[xx][yy] = 1;
     if ( paint[xx][yy] == 0 ){
          q.push( { xx , yy } );
          level[xx][yy] = level[x][y] + 1;
     }
     else{
         ans = min ( ans , Size[paint[xx][yy]] * Size[paint[sx][sy]] * level[x][y] );
     }

     }
 }
}
}


int main()
{

  MOHAMMAD
  ll t , tc = 0;
  cin >> t;
  while ( t-- ){
        cin >> row >> col;
        memset ( Size , 0  , sizeof Size );
         memset ( level , 0  , sizeof level );
          memset ( visit , 0  , sizeof visit );
           memset ( paint , 0  , sizeof paint );
           
          color = 0;
          ans = INF;
        for ( ll i = 0 ; i<row ; ++i ){
             for ( ll j = 0 ; j<col ; ++j ) cin >> grid[i][j];
        }

        for ( ll i = 0 ; i<row ; ++i ){
             for ( ll j = 0 ; j<col ; ++j ){
                if(visit[i][j] or grid[i][j]=='.' ) continue;
                len = 0 , color++;
                Flood_fill ( i , j , grid[i][j] );
                Size[color] = len;
             }
        }


        for ( ll i = 0 ; i<row ; ++i ){
             for ( ll j = 0 ; j<col ; ++j ){
                if( grid[i][j]=='.' ) continue;
                 memset ( visit , 0 , sizeof visit );
                 bfs ( i , j );

             }
        }

        cout << "Case " << ++tc << ": ";
        if ( color<2 ) cout << -1 << "\n";
        else cout << ans << "\n";
  }
}


/*







  Alhamdulillah
*/

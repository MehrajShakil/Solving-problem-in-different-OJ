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
const ll N = 2e5;
const ll INF = 1e15;
const ll limit = (1LL<<64) - 1;


int main()
{

  MOHAMMAD

  ll t;
  cin >> t;
  while ( t-- ){

      ll n , m;
      cin >> n >> m;
      ll rating[n+1] , cngrat[n+1][m+1] , rankk[n+1][m+1] , ratt[n+1][m+1];
      
      for ( ll i = 1 ; i<=n ; ++i ) cin >> rating[i];

      for ( ll i = 1 ;i<=n ; ++i ){
         for ( ll j = 1 ;j<=m ; ++j ){
            cin >> cngrat[i][j];
         }
      }

      for ( ll i = 1 ;i<=n ; ++i ){
         for ( ll j = 0 ;j<=m ; ++j ){
            rankk[i][j] = ratt[i][j] = 0;
            if ( j==0 ) cngrat[i][j] = 0; /// zero'th month means initial state.
         }
      }



           for ( ll i = 1 ; i<=m ; ++i ){ /// 1 to m months.

           vector < pair < ll , ll > > v;
           for ( ll row = 1 ; row<=n ; ++row ){ /// For, every person.
                rating[row]+=cngrat[row][i]; /// Rating change for every person.
                v.push_back( { rating[row] , row } );
                ratt[row][i] = rating[row];  /// This is for every month's rating change for every person.
           }

           sort ( all ( v ) );
           reverse ( all ( v ) );

           ll prev = -INF , now = 1 , cnt = 0;

           for ( auto it : v ){
          /// dbg ( it.first , now , cnt );
           cnt++;
           if ( prev == -INF ) {
               rankk[it.second][i] = now;
               prev = it.first;
               continue;
           }
           if ( prev==it.first ){
               rankk[it.second][i] = now;
           }
           else{
               now = cnt;
               rankk[it.second][i] = now;
           }
           prev = it.first;
        }

         //  for ( ll row = 1 ; row<=n ; ++row ){
         ///       dbg ( rankk[row][i] );
         //  }
         //  dbg ("----------------");
      }

      ll ans = 0;

      for ( ll i = 1 ;i<=n ; ++i ){
         ll mxrank = INF , mxrat = 0 , masrank = 0 , masrat = 0;
         for ( ll j = 1 ;j<=m ; ++j ){
             // dbg ( rankk[i][j] , ratt[i][j] );
              if ( mxrank>rankk[i][j] )  {
                mxrank = rankk[i][j];
                masrank = j;
              }
              if ( mxrat<ratt[i][j] )  {
                mxrat = ratt[i][j];
                masrat = j;
              }
         }
        // dbg ( masrank , masrat );
         if ( masrat!=masrank ) ans++;
      }

      cout << ans << "\n";

  }

}


/*

Explanation:



TODO :

  Alhamdulillah
*/

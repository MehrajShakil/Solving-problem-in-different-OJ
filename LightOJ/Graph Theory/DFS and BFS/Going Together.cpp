///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME


///   Every soul shall taste death.

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>



///  order_of_key return number of elements less than x.
///  find_by_order return index.
using namespace std;
using namespace __gnu_pbds;


#define MUHAMMAD        ios::sync_with_stdio(0);cin.tie(0);
#define all(x)          (x).begin(), (x).end()
#define AE              cout << fixed << setprecision(10);
#define ld              double
#define f               first
#define ss              second


/// faster.
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};


using ll = long long;
const ll MOD =  1e9+7;


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

const int N = 2e4 + 6;
const ll INF = 1e18;
const ld EPS   = 1e-6;
const ll limit = (1LL<<32) - 1;
const ll K = 1e6 + 1;

/// --------------------------------------------------------------

char grid[11][11];
ll dp[11][11][11][11][11][11];
ll n;
map < pair < int , int > , bool > mp;

struct st {
  pair < int , int > A , B , C;
};

bool check ( int x , int y ){
   if ( x < 1 or y < 1 or x > n or y > n or grid[x][y] == '#') return false;
   return true;
}

int bfs ( st data ){
    
   
   dp[data.A.f][data.A.ss][data.B.f][data.B.ss][data.C.f][data.C.ss] = 1;
   queue < st > q;
   q.push ( data );

   while ( q.size() ){
     st u = q.front();
     q.pop();

     if ( mp[u.A] and mp[u.B] and mp[u.C] and u.A!=u.B and u.B!=u.C and u.A!=u.C ) {
        return dp[u.A.f][u.A.ss][u.B.f][u.B.ss][u.C.f][u.C.ss];
     }

     for ( int i = 0 ; i < 4 ; ++i ){
        st v;
        v.A.f = u.A.f + dx4[i];
        v.A.ss = u.A.ss + dy4[i];
        if ( !check ( v.A.f , v.A.ss ) ) {
           v.A = u.A;
        }

        v.B.f = u.B.f + dx4[i];
        v.B.ss = u.B.ss + dy4[i];
        if ( !check ( v.B.f , v.B.ss ) ) {
           v.B = u.B;
        }

        v.C.f = u.C.f + dx4[i];
        v.C.ss = u.C.ss + dy4[i];
        if ( !check ( v.C.f , v.C.ss ) ) {
           v.C = u.C;
        }

        if ( v.A == v.B ){
            if ( v.B==v.C ){
                v.C = u.C;
            }
            v.A = u.A;
            v.B = u.B;
        }
        if ( v.A == v.C ){
            v.A = u.A;
            v.C = u.C;
        }
        if ( v.B==v.C ){
            v.B = u.B;
            v.C = u.C;
        }

     if ( dp[v.A.f][v.A.ss][v.B.f][v.B.ss][v.C.f][v.C.ss] == 0 ){
     q.push ( v );
     dp[v.A.f][v.A.ss][v.B.f][v.B.ss][v.C.f][v.C.ss] = dp[u.A.f][u.A.ss][u.B.f][u.B.ss][u.C.f][u.C.ss] + 1;
     }
     }
   }
  return -1;
}


void Solution ( int tc ){
  mp.clear();
  st data; 

  memset ( dp , 0 , sizeof dp );

  cin >> n;

  for ( int i = 1 ; i<=n ; i++ ){
    for ( int j = 1 ; j<=n ; j++ ) {
        cin >> grid[i][j];
        if ( grid[i][j] == 'A' ) {
            data.A = { i , j };
        }
        if ( grid[i][j] == 'B' ) {
            data.B = { i , j };
        }
        if ( grid[i][j] == 'C' ) {
            data.C = { i , j };
        }
        if ( grid[i][j] == 'X' ) {
            mp[ { i , j } ] = true;
        }
    }
  }
  ll x = bfs ( data ) - 1;
  if ( x == -2 ) cout << "Case " << tc << ": trapped\n";
  else cout << "Case " << tc << ": " << x << "\n";




  return;
}

int main()
{
    MUHAMMAD

    /// AE;

    /*
    #ifdef OJ
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    */

    int testcase = 1 , tc = 0;



    cin >> testcase;

    for ( int i = 1 ; i <= testcase ; ++i ){

       Solution( ++tc );
    }

    return 0;
}


/*


Explanation:

 Time :


----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/

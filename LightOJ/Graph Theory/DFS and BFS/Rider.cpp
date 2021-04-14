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


/// faster.
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};
int dx9[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; /// knight moves.
int dy9[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };


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

const int N = 3e4 + 1;
const ll INF = 1e18;
const ld EPS   = 1e-6;
const ll limit = (1LL<<32) - 1;
const ll K = 1e6 + 1;

/// --------------------------------------------------------------

int n , m , cnt = 0 , total = 0 , op = 0 , mn = 1e5;
char grid[11][11];
int dep[11][11];

void bfs ( int x , int y ){
    queue < pair < int , int > > q;
    q.push ( { x , y } );

    while ( q.size() ){
        pair < int , int > p = q.front();
        q.pop();
        x = p.first;
        y = p.second;
        for ( int i = 0 ; i < 8 ; i++ ){
            int xx = x + dx9[i];
            int yy = y + dy9[i];
            if ( xx < 1 or xx > n or yy < 1 or yy > m ) continue;

            if ( dep[x][y] + 1 < dep[xx][yy] ) {
                q.push ( { xx , yy } );
                dep[xx][yy] = dep[x][y] + 1;
                if ( grid[xx][yy] != '.' ) {
                    int digit = (grid[xx][yy] - '0');
                    op+=(dep[xx][yy]/digit);
                    if ( dep[xx][yy]%digit) op++;
                    total++;
                }
            }
        }
    }



}

void Solution ( int tc ){

  cin >> n >> m;

  for ( int i = 1 ; i <= n ; i++ ){
    for ( int j = 1 ; j <= m ; j++ ) {
        cin >> grid[i][j];
        if ( grid[i][j]!='.' ) cnt++;
    }
  }

  for ( int i = 1 ; i<=n ; i++ ){
    for ( int j = 1 ; j<=m ; j++ ){

         for ( int k = 0 ; k <= n ; ++k ){
            for ( int l = 0 ; l <=m ; ++l ) dep[k][l] = 1e5;
         }

         dep[i][j] = 0;
         bfs ( i , j );
         if ( grid[i][j]!='.' ) total++;
         if ( total == cnt ) mn = min ( mn , op );
         total = 0;
         op = 0;
    }
  }

  cout << "Case " << tc << ": " << ( mn == 1e5 ? -1 : mn ) << "\n";
  mn = 1e5;
  cnt = 0;
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

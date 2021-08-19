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
const ld PI = acos(-1.0);



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

/// Geometry section.
ld degree_to_radian( ld x ){
	ld ans = ((ld)(acos(-1.0)/180.0)*x);
	return ans;
}

//***********************************************  The END **********************************************************************************************************************************

const ll N = 2e5 + 5;
const ll INF = 1e18;
const ld EPS   = 1e-9;
const ll limit = (1LL<<32) - 1;
const ll K = 1e12;

/// --------------------------------------------------------------

int sz1[N];
int sz2[N];
int par1[N];
int par2[N];

/// ami.

void init(int u){
sz1[u] = sz2[u] = 1;
par1[u] = par2[u] = u;
}

int root1( int u ){
 while(par1[u]!=u) {
    par1[u] = par1[par1[u]];
    u = par1[u];
 }
 return u;
}

void uni1( int u , int v ){

   int ru = root1(u);
   int rv = root1(v);

   if ( sz1[ru] < sz1[rv] ) {
    par1[ru] = par1[rv];
    sz1[rv]+=sz1[ru];
   }
   else{
    par1[rv] = par1[ru];
    sz1[ru]+=sz1[rv];
   }
}

/// tumi.

int root2( int u ){
 while(par2[u]!=u) {
    par2[u] = par2[par2[u]];
    u = par2[u];
 }
 return u;
}

void uni2( int u , int v ){

   int ru = root2(u);
   int rv = root2(v);

   if ( sz2[ru] < sz2[rv] ) {
    par2[ru] = par2[rv];
    sz2[rv]+=sz2[ru];
   }
   else{
    par2[rv] = par2[ru];
    sz2[ru]+=sz2[rv];
   }
}




void Solution ( int tc ){

  int n , m1 , m2;
  cin >> n >> m1 >> m2;

  for ( int i = 1 ; i<=n ; ++i ) init(i);

  for ( int i = 1 ; i<=m1 ; ++i ){
    int u , v;
    cin >> u >> v;
    uni1(u,v);
  }

  for ( int i = 1 ; i<=m2 ; ++i ){
    int u , v;
    cin >> u >> v;
    uni2(u,v);
  }

  vector < pair < int , int > > v;

  for ( int i = 1 ; i<=n ; ++i ) {
    for ( int j = i+1; j <=n ; ++j ) {
        ll p1 = root1(i);
        ll p11 = root1(j);

        ll p2 = root2(i);
        ll p22 = root2(j);

        if ( p1!=p11 and p2!=p22 ) {
            uni1 ( i , j );
            uni2 ( i , j );
            v.push_back ( { i , j } );
        }

    }
  }

  cout << v.size( ) << "\n";
  for ( auto it : v ) {
    cout << it.first << " " << it.second << "\n";
  }


  return;
}

int main()
{

   MUHAMMAD;




   /// AE;

   /*
   #ifdef OJ
        freopen("window.in", "r", stdin);
        freopen("output.txt", "w", stdout);
   #endif
   */



    int testcase = 1 , tc = 0;




    /// cin >> testcase;

    for ( int i = 1 ; i <= testcase ; ++i ){
       Solution( ++tc );
    }


    return 0;
}


  /// __mhs, Do you check
  /// -> overflow
  /// -> array bound.


/*

 LCA:

 https://codeforces.com/contest/1304/problem/E

Explanation:

 Time :


----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/

///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME


//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

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

const int N = 3e4 + 1;
const ll INF = 1e18;
const ld EPS   = 1e-6;
const ll limit = (1LL<<32) - 1;
const ll K = 1e6 + 1;

/// Global...

int n , arr[N];

struct Tree{
      int num;
      int ind;
}tr[N<<2];

void build ( int node , int l , int r ){

    if ( l == r ) {
        tr[node].num = arr[l];
        tr[node].ind = l;
        return;
    }

    int mid = (l+r)>>1;
    int lc = node*2;
    int rc = lc + 1;

    build ( lc , l , mid );
    build ( rc , mid + 1 , r );

    if ( tr[lc].num < tr[rc].num ){
        tr[node].num = tr[lc].num;
        tr[node].ind = tr[lc].ind;
    }
    else{
        tr[node].num = tr[rc].num;
        tr[node].ind = tr[rc].ind;
    }
}

pair < int , int > query ( int node , int l , int r , int ql , int qr ){

   if ( l>qr or r<ql ) {
    return { N , N };
   }
   if ( l>=ql and r<=qr ) {
    return { tr[node].num , tr[node].ind };
   }

   int mid = (l+r)>>1;

   int lc = node*2;
   int rc = lc + 1;

   pair < int , int > p1 , p2;
   p1 = query ( lc , l , mid , ql , qr );
   p2 = query ( rc , mid + 1 , r , ql , qr );

   return min ( p1 , p2 );
}

int recur ( int lef , int rig ){
   if ( lef > rig ) return 0;

   pair < int , int > res;
   res = query ( 1 , 1 , n , lef , rig );
   int res1 = res.first*(rig-lef+1);
   int res2 = max ( recur ( lef , res.second - 1 ) , recur ( res.second + 1 , rig ) );

   return max ( res1 , res2 );
}

void solve ( int tc ){

  cin >> n;
  for ( int i = 1 ; i <= n ; i++ ) cin >> arr[i];

  build ( 1 , 1 , n );

  cout << "Case " << tc << ": " << recur ( 1 , n ) << "\n";

  return;
}

int main()
{
    MUHAMMAD

    /*
    #ifdef OJ
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    */

    int t = 1 , tc = 0;
    cin >> t;

    while ( t-- ){
       solve( ++tc );
    }

}


/*


Explanation:

 Time :
 
----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/

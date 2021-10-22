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
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};




using ll = long long;
const ll MOD =  1e9+7;
const ld PI = acos(-1.0);



typedef tree< int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>,null_type,greater<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multisetr;

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

const int N = 2e5 + 1;
const ll INF = 1e18;
const ld EPS   = 1e-9;
const ll limit = (1LL<<32) - 1;
const ll K = 1e5+1;

/// --------------------------------------------------------------

vector < int > e[N];
int Node;
int arr[N];
int In[N];
int Out[N];
int cur = 1;
ll tr[N<<2];
int who[N];
int q;

void dfs ( int node , int par = -1 ) {
   In[node] = cur++;
   who[cur-1] = node;
   for ( auto child : e[node] ){
    if ( child == par ) continue;
    dfs ( child , node );
   }
   Out[node] = cur;
}

void build ( int node , int l , int r ){
    if ( l == r ) {
        tr[node] = arr[who[l]];
        return;
    }
    int mid = (l+r)>>1;
    int lc = node*2;
    int rc = lc+1;

    build (lc,l,mid);
    build (rc,mid+1,r);

    tr[node]=tr[lc]+tr[rc];
}

void update ( int node , int l , int r , int index , int value ){

     if ( l == r ) {
        tr[node] = value;
        return;
     }
     int mid = (l+r)>>1;
     int lc = node*2;
     int rc = lc+1;

     if ( index <= mid ) update(lc,l,mid,index,value);
     else update(rc,mid+1,r,index,value);

     tr[node]=tr[lc]+tr[rc];
}

ll query ( int node , int l , int r , int ql , int qr ){

  if ( l > qr or r < ql ) return 0;
  if ( l>=ql and r<=qr ) return tr[node];

  int mid = (l+r)>>1;
  int lc = node*2;
  int rc = lc+1;

  ll x = query(lc,l,mid,ql,qr);
  ll y = query(rc,mid+1,r,ql,qr);

  return x+y;
}




void Solution ( int tc ){

  cin >> Node >> q;
  for ( int i = 1 ; i<=Node ; ++i ) cin >>  arr[i];

  for ( int i = 1 ; i < Node ; ++i ) {
    int u , v;
    cin >> u >> v;
    e[u].push_back ( v );
    e[v].push_back ( u );
  }

  dfs(1);
  build(1,1,Node);

  for ( int i = 1 ; i<=q ; ++i ) {
    int task , node , x;
    cin >> task;
    if ( task == 1 ) {
        cin >> node >> x;
        arr[node] = x;
        update(1,1,Node,In[node],x);
    }
    else{
        cin >> node;
        cout << query(1,1,Node,In[node],Out[node]-1) << "\n";
    }
  }

  return;
}

int main()
{
   MUHAMMAD;

   /// AE;

   /*
   #ifdef OJ
        freopen("input.txt", "r", stdin);
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
  /// -> overflow ?
  /// -> array bound ?


/*

Explanation:

 Time :


----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/
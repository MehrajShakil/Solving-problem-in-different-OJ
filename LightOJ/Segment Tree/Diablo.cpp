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

const int N = 2e5 + 5;
const ll INF = 1e18;
const ld EPS   = 1e-9;
const ll limit = (1LL<<32) - 1;
const ll K = 1e12;

/// --------------------------------------------------------------


ll tr[N<<2] , lz[N<<2];


///1. Merge left and right
ll combine (ll left, ll right) {
    return left + right;
}

///2. Push lazy down and merge lazy
void propagate(ll u, ll st, ll en) {
    if (lz[u] == -1) return;
    tr[u]+= (en-st+1)*lz[u];
    if (st!=en) {
        if ( lz[2*u] == -1 ) lz[2*u] = 0;
        if ( lz[2*u+1] == -1 ) lz[2*u+1] = 0;
        lz[2*u]+= lz[u];
        lz[2*u+1]+= lz[u];
    }
    lz[u] = -1;
}


void build(ll u, ll st, ll en) {
    if (st==en) {
        tr[u] = 0;          ///3. Initialize
        lz[u] = -1;
    }
    else {
        ll mid = (st+en)/2;
        build(2*u, st, mid);
        build(2*u+1, mid+1, en);
        tr[u] = combine(tr[2*u], tr[2*u+1]);
        lz[u] = -1;              ///3. Initialize
    }
}

void update(ll u, ll st, ll en, ll l, ll r, ll x) {
    propagate(u, st, en);
    if (r<st || en<l)  return;
    else if (l<=st && en<=r) {
        lz[u] = x;             ///4. Merge lazy
        propagate(u, st, en);
    }
    else {
        ll mid = (st+en)/2;
        update(2*u, st, mid, l, r, x);
        update(2*u+1, mid+1, en, l, r, x);
        tr[u] = combine(tr[2*u], tr[2*u+1]);
    }
}

ll query(ll u, ll st, ll en, ll l, ll r) {
    propagate(u, st, en);
    if (r<st || en<l)  return 0;        /// 5. Proper null value
    else if (l<=st && en<=r)    return tr[u];
    else {
        ll mid = (st+en)/2;
        return combine(query(2*u, st, mid, l, r), query(2*u+1, mid+1, en, l, r));
    }
}

void Solution ( int tc ){

  for ( int i = 0 ; i < 4*N ; ++i ) tr[i] = 0 , lz[i] = -1;

  int n , q;
  cin >> n >> q;

  vector < int > v;

  for ( int i = 1 ; i <= n ; i++ ) {
    int x;
    cin >> x;
    v.push_back ( x );
  }

  cout << "Case " << tc << ":\n";

  for ( int i = 1 ; i<=q ; i++ ) {
    char c;
    int x;
    cin >> c >> x;
    if ( c == 'c' ) {

       if ( x > v.size() ) cout << "none\n";
       else{
        int lo = 1;
        int hi = v.size();

        int ans = N;

        while ( lo<=hi ) {
            int mid = (lo+hi)>>1;
            int bad = query ( 1 , 1 , N-1 , 1 , mid );
            int rem = mid - bad;
            if ( rem == x ) {
                ans = min ( ans , mid );
                hi = mid - 1;
            }
            else if ( rem > x ){
                hi = mid - 1;
            }
            else lo = mid + 1;
        }

        if ( ans > v.size() ) cout << "none\n";
        else {
            cout << v[ans-1] << "\n";
            update ( 1 , 1 , N-1 , ans , ans , 1 );
        }

       }
    }
    else{
        v.push_back ( x );
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
        freopen("window.in", "r", stdin);
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

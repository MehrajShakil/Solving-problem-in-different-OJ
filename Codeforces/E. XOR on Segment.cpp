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
typedef tree< int, null_type, greater<int>, rb_tree_tag,tree_order_statistics_node_update> Rordered_set;
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

const int N = 1e5 + 5;
const ll INF = 1e18;
const ld EPS   = 1e-9;
const ll limit = (1LL<<32) - 1;
const ll K = 1e12;

/// --------------------------------------------------------------



ll tr[N<<2][25] , lz[N<<2];
ll n;
ll arr[N];
ll q;


///1. Merge left and right
ll combine (ll left, ll right) {
    return left + right;
}

///2. Push lazy down and merge lazy
void propagate(ll u, ll st, ll en) {
    if (lz[u] == -1) return;

    int total = en - st + 1;

    for ( int i = 0 ; i < 24 ; ++i ){

            if ( (1LL<<i)&lz[u] )tr[u][i] = total - tr[u][i];
    }

    if (st!=en) {
        if ( lz[2*u] == -1 ) lz[2*u] = 0;
        if ( lz[2*u+1] == -1 ) lz[2*u+1] = 0;
        lz[2*u]^= lz[u];
        lz[2*u+1]^= lz[u];
    }
    lz[u] = -1;
}


void build(ll u, ll st, ll en) {
    if (st==en) {
        ll x = arr[st];
        for ( int i = 0 ; i < 24 ; ++i ) {  ///3. Initialize
            if ( x&(1LL<<i) ) tr[u][i] = 1;
            else tr[u][i] = 0;
        }

        lz[u] = -1;
    }
    else {
        ll mid = (st+en)/2;
        build(2*u, st, mid);
        build(2*u+1, mid+1, en);
        for ( int i = 0 ; i < 24 ; ++i ) {
        tr[u][i] = combine(tr[2*u][i], tr[2*u+1][i]);
        }
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

        for ( int i = 0 ; i < 24 ; ++i ) {
        tr[u][i] = combine(tr[2*u][i], tr[2*u+1][i]);
        }
    }
}

ll query(ll u, ll st, ll en, ll l, ll r) {
    propagate(u, st, en);
    if (r<st || en<l)  return 0;        /// 5. Proper null value
    else if (l<=st && en<=r)    {
        ll res = 0;
        for ( int i = 0 ; i < 24 ; ++i ) {
             ll cnt = tr[u][i];
             res+=(cnt*(1LL<<i));
        }
        return res;
    }
    else {
        ll mid = (st+en)/2;
        return combine(query(2*u, st, mid, l, r), query(2*u+1, mid+1, en, l, r));
    }
}

void Solution ( int tc ){

  cin >> n;

  for ( int i = 1 ; i<=n ; ++i ) cin >> arr[i];

  build ( 1 , 1 , n );

  cin >> q;

  for ( int i = 1 ; i<=q ; ++i ) {
    ll task , l , r , x;

    cin >> task;

    if ( task == 1 ) {
        cin >> l >> r;
        cout << query ( 1 , 1 , n , l , r ) << "\n";
    }
    else{
        cin >> l >> r >> x;
        update ( 1 , 1 , n , l , r , x );
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

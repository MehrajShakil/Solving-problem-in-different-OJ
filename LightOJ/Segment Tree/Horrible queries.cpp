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

const int N = 1e5 + 5;
const ll INF = 1e18;
const ld EPS   = 1e-9;
const ll limit = (1LL<<32) - 1;
const ll K = 1e12;

/// --------------------------------------------------------------


struct info {
  ll propagate;
  ll value;
}tr[N<<2];

int n , q;

void build ( int node , int l , int r ){

    if ( l == r ) {
        tr[node].value = 0;
        tr[node].propagate = 0;
        return;
    }

    int mid = (l+r)>>1;
    int lc = node*2;
    int rc = node*2+1;

    build ( lc , l , mid );
    build ( rc , mid + 1 , r );

    tr[node].value = 0;
    tr[node].propagate = 0;
}

void update ( int node , int  l , int r , int ql , int qr , int x ){
     if ( l > qr or r < ql ) return;
     if ( l>=ql and r<=qr ){
         tr[node].value+=((r-l+1)*x);
         tr[node].propagate+=x;
         return;
     }

     int mid = (l+r)>>1;
     int lc = node*2;
     int rc = lc+1;

     update ( lc , l , mid , ql , qr , x );
     update ( rc , mid + 1 , r , ql , qr , x );
     tr[node].value = tr[lc].value + tr[rc].value + (tr[node].propagate*(r-l+1));
}

ll query ( int node , int l , int r , int ql , int qr , ll carry = 0 ){

    if ( l > qr or r < ql ) return 0LL;
    if ( l>=ql and r<=qr ){
        return tr[node].value + carry*(r-l+1);
    }

    int mid = (l+r)>>1;
    int lc = node*2;
    int rc = lc+1;

    ll lef = query ( lc , l , mid , ql , qr , carry + tr[node].propagate );
    ll rig = query ( rc , mid + 1 , r , ql , qr , carry + tr[node].propagate );

    return lef + rig;
}

void Solution ( int tc ){

  cin >> n >> q;

  for ( int i = 1 ; i <= 4*n ; ++i ) tr[i].propagate = tr[i].value = 0;

  cout << "Case " << tc << ":\n";

  for ( int i = 1 ; i<=q ; i++ ) {
    int task , x , y , value;
    cin >> task;
    if ( task == 0 ) {
        cin >> x >> y >> value;
        update ( 1 , 1 , n , x+1 , y+1 , value );
    }
    else {
        cin >> x >> y;
        ll res = query ( 1 , 1 , n , x+1 , y+1 );
        cout << res << "\n";
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

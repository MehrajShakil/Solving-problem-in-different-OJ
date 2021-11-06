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
const ll MOD = 1e9+7;
/// const ld PI = acos(-1.0);



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


//***********************************************  The END **********************************************************************************************************************************

const ll N = 1e6 + 27;
const ll INF = 1e18;
const ld EPS   = 1e-9;
const ll limit = (1LL<<32) - 1;
const ll K = N*N;

/// --------------------------------------------------------------

vector < ll > primes, temp, revstore(N,0) , subtract(N+1,0), done(N+1,0);
vector < pair < ll , ll > > store[N];
bitset<N+1> bs;
ll n;
ll arr[N];

void sieve(){
bs.set();
bs[0] = bs[1] = 0;
for ( ll i = 2 ; i < 1e3+10 ; ++i ) {
    if ( bs[i] ) {
        primes.push_back( i );
        for ( ll j = i*i ; j < 1e3+10 ; j+=i ) bs[j] = 0;
    }
}
}

int Len = 0;
ll x;

void subset1( int ind , ll mul , int len = 0 ){

   if ( ind == Len ) {
    if ( mul > 1 ){
    revstore[mul]++;
    }
   }
   else{
    subset1(ind+1,mul*temp[ind],len+1);
    subset1(ind+1,mul,len);
   }
   return;
}

void subset( int ind , ll mul , int len = 0 ){

   if ( ind == Len ) {
    if ( mul > 1 ){
    store[x].push_back( { mul , len } );
    }
   }
   else{
    subset(ind+1,mul*temp[ind],len+1);
    subset(ind+1,mul,len);
   }
   return;
}

void pre(){
  for ( ll i = 1 ; i<=n ; ++i ) {
    ll cur = arr[i];
    for ( auto p : primes ) {
        bool ok = 0;
        while(cur%p==0){
            cur/=p;
            ok = 1;
        }
       if ( ok ) temp.push_back ( p ) , Len++;
    }
    if ( cur > 1 ) temp.push_back ( cur ) , Len++;
    x = arr[i];
    subset1( 0 , 1 );
    if ( done[x] == 0 ) subset( 0 , 1 );
    done[x] = 1;
    Len = 0;
    temp.clear();
  }
}


void Solution ( int tc ){

 cin >> n;


 for ( int i = 1 ; i <= n ; ++i ) cin >> arr[i];

 pre();

 ll co = 0;

 for ( int i = 1 ; i<=n ; ++i ) {
    ll x = arr[i];
    ll have = n-i+1;
    if ( x == 1 ) {
        co+=(n-i);
        continue;
    }
    for ( auto[a,b] : store[x] ) {
        ll cur = revstore[a];
        if ( !(b&1) ) cur = -cur;
        have-=cur;
        revstore[a]--;
    }
    co+=have;
 }
 cout << co << "\n";
 return;
}

int main()
{
   MUHAMMAD;

   sieve();


   // AE;

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

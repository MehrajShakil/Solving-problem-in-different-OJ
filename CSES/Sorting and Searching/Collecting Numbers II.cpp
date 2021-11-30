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
const ll MOD = 998244353;
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

const ll N = 1e5 + 27;
const ll INF = 1e18;
const ld EPS   = 1e-9;
const ll limit = (1LL<<32) - 1;
const ll K = N*N;

/// --------------------------------------------------------------



void Solution ( int tc ){

 int n , m;
 cin >> n >> m;

 int arr[n+1];
 vector<int> pos(n+1,-1);

 for ( int i = 1 ; i<=n ; ++i ) {
    cin >> arr[i];
    pos[arr[i]] = i;
 }

 int last = -1;

 int op = 1;
 pos[0] = -1;

 for ( int i = 2 ; i <= n ; ++i ) {
    if ( pos[i-1] > pos[i] ) op++;
 }

 /// dbg ( op );

 for ( int i = 1 ; i<=m ; ++i ) {
    int l , r;
    cin >> l >> r;

    int x = arr[l];
    int y = arr[r];

    map < int , int > done;
    vector<pair<int,int>> temp;

    ///for x
    if(x-1){
        if(!done[x-1])temp.push_back({x-1,pos[x-1]});
        done[x-1] = 1;
    }
    if(x){
        if(!done[x])temp.push_back({x,pos[x]});
        done[x] = 1;
    }
    if(x+1<=n){
        if(!done[x+1])temp.push_back({x+1,pos[x+1]});
        done[x+1] = 1;
    }

    ///for y
    if(y-1){
        if(!done[y-1])temp.push_back({y-1,pos[y-1]});
        done[y-1] = 1;
    }
    if(y){
        if(!done[y])temp.push_back({y,pos[y]});
        done[y] = 1;
    }
    if(y+1<=n){
        if(!done[y+1])temp.push_back({y+1,pos[y+1]});
        done[y+1] = 1;
    }

    sort(all(temp));

    for( int j = 1; j<temp.size() ; ++j ){
        if(temp[j-1].second > temp[j].second ) op--;
    }

    swap(arr[l],arr[r]);

    pos[arr[l]] = l;
    pos[arr[r]] = r;

    temp.clear();
    done.clear();

    x = arr[l];
    y = arr[r];




    ///for x
    if(x-1){
        if(!done[x-1])temp.push_back({x-1,pos[x-1]});
        done[x-1] = 1;
    }
    if(x){
        if(!done[x])temp.push_back({x,pos[x]});
        done[x] = 1;
    }
    if(x+1<=n){
        if(!done[x+1])temp.push_back({x+1,pos[x+1]});
        done[x+1] = 1;
    }

    ///for y
    if(y-1){
        if(!done[y-1])temp.push_back({y-1,pos[y-1]});
        done[y-1] = 1;
    }
    if(y){
        if(!done[y])temp.push_back({y,pos[y]});
        done[y] = 1;
    }
    if(y+1<=n){
        if(!done[y+1])temp.push_back({y+1,pos[y+1]});
        done[y+1] = 1;
    }

    sort(all(temp));

    for( int j = 1; j<temp.size() ; ++j ){
        if(temp[j-1].second > temp[j].second ) op++;
    }

    cout << op << "\n";
 }



 return;
}

int main()
{
  MUHAMMAD;


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

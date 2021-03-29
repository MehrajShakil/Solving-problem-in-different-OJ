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

const int N = 1e9 + 1;
const ll INF = 1e18;
const ld EPS   = 1e-9;
const ll limit = (1LL<<32) - 1;
const int K = 1e6 + 1;

/// Global...

vector < int > e[105];
int s , d;
int SourceToAny[105] , DestinationToAny[105];


int bfs ( int node ){
    
    int lim = node;
    for ( int i = 1 ; i<=node ; ++i ){
        SourceToAny[i] = DestinationToAny[i] = N;
    }

    /// src to any.
    queue < int > q;
    q.push ( s );
    SourceToAny[s] = 0;
    while ( q.size() ) {
        node = q.front();
        q.pop();
        for ( auto child : e[node] ) {
            if ( SourceToAny[node] + 1 < SourceToAny[child] ){
                SourceToAny[child] = SourceToAny[node] + 1;
                q.push ( child );
            }
        }
    }

    /// des to any.
    q.push ( d );
    DestinationToAny[d] = 0;
    while ( q.size() ) {
        node = q.front();
        q.pop();
        for ( auto child : e[node] ) {
            if ( DestinationToAny[node] + 1 < DestinationToAny[child] ){
                DestinationToAny[child] = DestinationToAny[node] + 1;
                q.push ( child );
            }
        }
    }
    int mx = 0;
    for ( int i = 1 ; i<=lim ; ++i ) {
        /// dbg ( i , SourceToAny[i] , DestinationToAny[i] );
        mx = max ( mx , SourceToAny[i] + DestinationToAny[i] );
    }
    return mx;
}


void solve ( int tc ){

   int n , r;
   cin >> n >> r;

   for ( int i = 1 ; i <= n ; ++i ) e[i].clear();

   for ( int i = 0 ; i < r ; i++ ) {
    int u , v;
    cin >> u >> v;
    u++,v++;
    e[u].push_back ( v );
    e[v].push_back ( u );
   }

   cin >> s >> d;
   s++,d++;

   cout << "Case " << tc << ": " << bfs ( n ) << "\n";

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

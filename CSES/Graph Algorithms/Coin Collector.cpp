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


using ll = long long int;
const ll MOD =  998244353;
const ld PI = acos(-1.0);


typedef tree< int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree< int, null_type, greater<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set_boro;

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

const ll N = 2e5+10;
const ll INF = 1e18;
const ld EPS   = 1e-9;
const ll limit = (1LL<<32) - 1;
const ll K = 1e5+1;

/// --------------------------------------------------------------

/* SCC from BenQ */
struct SCC {
	int N;
    vector<vector<int>> adj, radj;
	vector<int> todo, comps, comp;
    vector<bool> vis;

    /// Initialization
	void init(int _N) {
	    N = _N;
		adj.resize(N);
        radj.resize(N);
        comp = vector<int>(N,-1);
        vis.resize(N);
	}

	/// added edges.
	void ae(int x, int y) {
        adj[x].push_back(y);
        radj[y].push_back(x);
    }

    /// find topoSort order.
	void dfs(int x) {
		vis[x] = 1;
        for(auto y : adj[x]) {
            if(vis[y]) continue;
            dfs(y);
        }
		todo.push_back(x);
    }

    /// find all scc
	void dfs2(int x, int v){  /// same dad of everyone 'v'.
		comp[x] = v;
		for (auto y : radj[x]) {
            if (comp[y] == -1) dfs2(y,v);
		}
    }

    /// build scc
	void gen(int _N) { // fills allComp
		for ( int i = 1 ; i < N ; ++i ){
        if (!vis[i]) dfs(i);
		}
		reverse(all(todo));
		for( auto x : todo ){
            if (comp[x] == -1) {
			dfs2(x,x);
            comps.push_back(x);
			}
		}
	}
}scc;

ll dp[N];
ll eachGroup[N];

vector<int> e[N];


ll recur ( int node ) {
  //dbg ( node , dp[node] );
  if(dp[node]!=-1) return dp[node];
  dp[node] = eachGroup[node];
  for ( auto child : e[node] ) {
    dp[node] = max ( dp[node] , eachGroup[node] + recur( scc.comp[child] ) );
  }
  //dbg ( cur , mx );
  return dp[node];
}

void Solution ( int tc ){



    int n , q;
    cin >> n >> q;

    scc.init(n+1);
    ll arr[n+1];

    for ( int i  = 1 ; i<=n ; ++i ) {
        cin >> arr[i];
        dp[i] = -1;
        eachGroup[i] = 0;
    }

    for ( int i = 1 ; i<=q ; ++i ) {
        int u , v;
        cin >> u >> v;
        scc.ae(u,v);
    }

    scc.gen(n);

    for ( int i = 1 ; i<=n ; ++i ){
        eachGroup[scc.comp[i]]+=arr[i];
        for ( auto child : scc.adj[i] ) {
             if(scc.comp[child]==scc.comp[i] ) continue;
            e[scc.comp[child]].push_back(scc.comp[i]);
        }
    }

    ll ans = 0;

    for ( auto child : scc.comps ){
       // dbg ( child );
        ans = max ( ans , recur(child) );
    }

    cout << ans << "\n";

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
  /// -> overflow
  /// -> array bound.


/*

 LCA:


Explanation:

 Time :


----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/

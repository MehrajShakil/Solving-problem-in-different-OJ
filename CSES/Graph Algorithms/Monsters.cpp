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

const ll N = 1e3+10;
const ll INF = 1e18;
const ld EPS   = 1e-9;
const ll limit = (1LL<<32) - 1;
const ll K = 1e5+1;

/// --------------------------------------------------------------

int n,m;
char grid[N][N];

vector<vector<int>> bfs(queue<pair<int,int>> &q){
     vector<vector<int>> cost;
     cost.resize(n+1);
     for ( int i = 0 ; i <= n ; ++i ) {
        cost[i].resize(m+1);
        for(int j = 0 ; j <= m ; ++j ) cost[i][j] = n*m+10;
     }

     queue<pair<int,int>> temp;

     while(q.size()){
        pair<int,int> p = q.front();q.pop();
        cost[p.first][p.second] = 0;
        temp.push(p);
     }

     while(temp.size()){
        pair<int,int> p = temp.front();temp.pop();
        q.push(p);
     }

     while(q.size()){
        pair<int,int> p = q.front();q.pop();
        for ( int i = 0 ; i < 4 ; ++i ) {
            int x = p.first + dx4[i];
            int y = p.second + dy4[i];
            if(x>n or x < 1 or y > m or y < 1 or grid[x][y]=='#' ) continue;
            if(cost[p.first][p.second]+1<cost[x][y]){
              cost[x][y] = cost[p.first][p.second]+1;
              q.push( { x , y } );
            }
        }
     }
     return cost;
}

char go ( int i ) {
    if(i==0) return 'U';
    if(i==1) return 'D';
    if(i==2) return 'L';
    if(i==3) return 'R';
}


void Solution ( int tc ){

     cin >> n >> m;

     queue<pair<int,int>> q,qq;

     for ( int i = 1 ; i<=n ; ++i ) {
        for ( int j = 1 ; j<=m ; ++j ) {
            cin >> grid[i][j];
            if(grid[i][j]=='M') q.push({i,j});
            if(grid[i][j]=='A') qq.push({i,j});
        }
     }

     vector<vector<int>> monster = bfs(q);
     vector<vector<int>> cost = bfs(qq);

     int posX = -1;
     int posY = -1;

     bool done = false;
     for ( int i = 1 ; i<=n ; ++i ) {
        for ( int j = 1 ; j<=m ; ++j ) {
            /// dbg ( i , j , cost[i][j] , monster[i][j] );
            if( (i==1 or j==1 or i == n or j == m) and cost[i][j] < monster[i][j] ) {
                posX = i;
                posY = j;

                done = true;
                break;
            }
        }
        if(done) break;
     }

     if(posX==-1) cout << "NO\n";
     else{
        cout << "YES\n";
        int value = cost[posX][posY];
        string seq = "";

        /// dbg(value, posX , posY );

        while(value){
            for ( int i = 0 ; i < 4 ; ++i ) {
                int x = posX + dx4[i];
                int y = posY + dy4[i];
                /// dbg ( x , y , cost[x][y] , value );
                if(x>n or x < 1 or y > m or y < 1 ) continue;
                if(cost[x][y]==value-1){
                    /// dbg ( x , y );
                    posX = x;
                    posY = y;
                    seq+=go(i);
                    break;
                }
            }
            value--;
        }
        reverse(all(seq));
        cout << seq.size() << "\n";
        cout << seq << "\n";
     }
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

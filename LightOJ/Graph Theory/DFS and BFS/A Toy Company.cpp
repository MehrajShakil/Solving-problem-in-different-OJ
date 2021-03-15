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

const ll N = 2e5 + 5;
const ll INF = 1e18;
const ld EPS   = 1e-9;
const ll limit = (1LL<<32) - 1;
const int K = 1e3 + 1;

/// Global...
int vis[26][26][26];
int dis[26][26][26];

int drx[6] = { 0 , 0 , 0 , 0 , 1 , -1 };
int dry[6] = { 0 , 0 , 1 , -1 , 0 , 0 };
int drz[6] = { 1 , -1 , 0 , 0 , 0 , 0 };

string send ( int a , int b , int c ){
   char c1 = a + 'a';
   char c2 = b + 'a';
   char c3 = c + 'a';
   string s ="";
   s+=c1;s+=c2;s+=c3;
   return s;
}

int go ( int x ){

  if ( x == -1 ) return x = 25;
  if ( x == 26 ) return x = 0;
  else return x;
}

void solve ( int tc ){

   memset ( vis , 0 , sizeof vis );
   string a , b;
   int n;
   cin >> a >> b >> n;

   for ( int i = 1 ; i<=n ; ++i ){
      string x , y , z;
      cin >> x >> y >> z;

      for ( int j = 0 ; j < x.size() ; ++j ){
        for ( int k = 0 ; k < y.size() ; ++k ){
            for ( int l = 0 ; l < z.size() ; ++l ){
                vis[x[j]-'a'][y[k]-'a'][z[l]-'a'] = -1;
            }
        }
      }
   }

   for ( int i = 0 ; i < 26 ; ++i ){
    for ( int j = 0 ; j < 26 ; ++j ){
        for ( int k = 0 ; k < 26 ; ++k ) dis[i][j][k] = 1e9;
    }
   }

   queue < pair < string , int > > q;

   dis[a[0]-'a'][a[1]-'a'][a[2]-'a'] = 0;
   q.push ( { a , 0 } );


   while ( q.size() ){
       pair < string , int > p = q.front();
       q.pop();

       for ( int i = 0 ; i < 6 ; ++i ){
        int c1 = go(drx[i] + p.first[0]-'a');
        int c2 = go(dry[i] + p.first[1]-'a');
        int c3 = go(drz[i] + p.first[2]-'a');

        if ( vis[c1][c2][c3] == -1 ) continue;
        
        if ( p.second + 1 < dis[c1][c2][c3] ) {
            dis[c1][c2][c3] = p.second + 1;
            q.push ( { send ( c1 , c2 , c3 ) , dis[c1][c2][c3] } );
        }
       }
   }

   
   cout << "Case " << tc << ": ";
   if ( vis[a[0]-'a'][a[1]-'a'][a[2]-'a']!=-1 and  dis[b[0]-'a'][b[1]-'a'][b[2]-'a']!=1e9 ) cout << dis[b[0]-'a'][b[1]-'a'][b[2]-'a'] << "\n";
   else cout << "-1\n";



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

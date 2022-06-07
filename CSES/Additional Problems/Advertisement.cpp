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
#define AE              cout << fixed << setprecision(13);

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};


using ll = long long int;
const ll MOD =  1e9+7;


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

//***********************************************  The END **********************************************************************************************************************************

const ll N = 2e5+10;
const ll INF = 1e18;
const ll limit = (1LL<<32) - 1;
const ll K = 1e5+1;

/// --------------------------------------------------------------

struct Sparse
{
   int n,lg;
   vector<vector<int> >sparse_mx,sparse_mn;
   vector<int>A;
   void init(int tmp)
   {
       n=tmp;
       A.resize(n+3);
       lg=32-__builtin_clz(n+2);// 64 if nmx > 10^9
       sparse_mx=vector< vector<int> >(n+2,vector<int>(lg));

   }
   void abr_init(int aa[])
   {
       for(int i=1;i<=n;i++)A[i]=aa[i];
       build_table();
   }
   void build_table()
   {
        for(int i=1;i<=n;i++)sparse_mx[i][0]=A[i];
        for(int k=1,p=1;k<lg;k++,p<<=1)
        {
            for(int i=1;i+p+p<=n+1;i++)
            {
                sparse_mx[i][k]=min(sparse_mx[i][k-1],sparse_mx[i+p][k-1]);

            }
        }
   }
   int qmn(int l,int r)
   {
       int len=r-l+1;
       int k=32-__builtin_clz(len)-1;
       return min(sparse_mx[l][k],sparse_mx[r-(1<<k)+1][k]);
   }
};


void Solution ( int tc ){

  Sparse A;
  int n;
  cin >> n;

  int arr[n+1];
  for(int i = 1 ; i<=n ; ++i ) cin >> arr[i];

  A.init(n+1); A.abr_init(arr);

  ll mx = 0;
  for ( int i = 1 ; i<=n ; ++i ) {
    int lo = i;
    int hi = n;
    ll bam;
    ll dan;
    while(lo<=hi){
        int mid = (lo+hi)>>1;
        int mn = A.qmn(i,mid);
        if(mn>=arr[i]) lo = mid + 1;
        else hi = mid - 1;
    }
    dan = lo - 1;

    lo = 1;
    hi = i;

    while(lo<=hi){
        int mid = (lo+hi)>>1;
        int mn = A.qmn(mid,i);
        if(mn>=arr[i]) hi = mid - 1;
        else lo = mid + 1;
    }
    bam = hi+1;
    mx = max(mx,(dan-bam+1)*ll(arr[i]));
  }

  cout << mx << "\n";

  return;
}

int main()
{

   MUHAMMAD;



  // AE;

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

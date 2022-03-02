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
const ll MOD =  1e9+7;
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

const ll N = 2e5+1;
const ll INF = 1e18;
const ld EPS   = 1e-9;
const ll limit = (1LL<<32) - 1;
const ll K = 1e5+1;

/// --------------------------------------------------------------

struct Node{

    int pre1;
    int suf1;
    int sub1;
    int pre0;
    int suf0;
    int sub0;

    Node(){
    pre1 = suf1 = sub1 = 0;
    pre0 = suf0 = sub0 = 0;
    }

}tr[N<<2];

string s;

void build(int node, int l, int r){
    Node bame,dane,res;
    if(l==r){
        if(s[l]=='0'){
            res.pre0=res.sub0=res.suf0=1;
        }
        else{
            res.pre1=res.sub1=res.suf1=1;
        }
        tr[node]=res;
    }
    else{
        int mid = (l+r)>>1;
        int lc = node*2;
        int rc = lc+1;

        build(lc,l,mid);
        build(rc,mid+1,r);

        bame = tr[lc];
        dane = tr[rc];
        res.pre0 = bame.pre0;
        res.pre1 = bame.pre1;

        if(res.pre0==mid-l+1){
            res.pre0+=dane.pre0;
        }
        if(res.pre1==mid-l+1){
            res.pre1+=dane.pre1;
        }

        res.suf0 = dane.suf0;
        res.suf1 = dane.suf1;

        if(res.suf0==r-mid){
            res.suf0+=bame.suf0;
        }

        if(res.suf1==r-mid){
            res.suf1+=bame.suf1;
        }

        res.sub0 = max(bame.sub0,dane.sub0);
        res.sub0 = max(res.sub0,res.pre0);
        res.sub0 = max(res.sub0,res.suf0);
        res.sub0 = max(res.sub0,bame.suf0+dane.pre0);

        res.sub1 = max(bame.sub1,dane.sub1);
        res.sub1 = max(res.sub1,res.pre1);
        res.sub1 = max(res.sub1,res.suf1);
        res.sub1 = max(res.sub1,bame.suf1+dane.pre1);

        tr[node] = res;
    }
}

void update(int node,int l,int r,int pos){
    Node bame,dane,res;
    if(l==r){
        if(s[l]=='0'){
            res.pre0=res.sub0=res.suf0=1;
        }
        else{
            res.pre1=res.sub1=res.suf1=1;
        }
        tr[node]=res;
    }
    else{
        int mid = (l+r)>>1;
        int lc = node*2;
        int rc = lc+1;

        if(pos<=mid)update(lc,l,mid,pos);
        else update(rc,mid+1,r,pos);

        bame = tr[lc];
        dane = tr[rc];
        res.pre0 = bame.pre0;
        res.pre1 = bame.pre1;

        if(res.pre0==mid-l+1){
            res.pre0+=dane.pre0;
        }
        if(res.pre1==mid-l+1){
            res.pre1+=dane.pre1;
        }

        res.suf0 = dane.suf0;
        res.suf1 = dane.suf1;

        if(res.suf0==r-mid){
            res.suf0+=bame.suf0;
        }

        if(res.suf1==r-mid){
            res.suf1+=bame.suf1;
        }

        res.sub0 = max(bame.sub0,dane.sub0);
        res.sub0 = max(res.sub0,res.pre0);
        res.sub0 = max(res.sub0,res.suf0);
        res.sub0 = max(res.sub0,bame.suf0+dane.pre0);

        res.sub1 = max(bame.sub1,dane.sub1);
        res.sub1 = max(res.sub1,res.pre1);
        res.sub1 = max(res.sub1,res.suf1);
        res.sub1 = max(res.sub1,bame.suf1+dane.pre1);

        tr[node] = res;
    }
}


void Solution ( int tc ){

  cin >> s;

  int n;
  cin >> n;
  int len = s.size();
  s = "#" + s;



  build(1,1,len);

  for ( int i = 1 ; i <= n ; ++i ) {
    int x;
    cin >> x;

    if(s[x]=='1') s[x] = '0';
    else s[x] = '1';
    update(1,1,len,x);
    int mx = tr[1].pre0;
    mx = max (mx,tr[1].pre1);
    mx = max (mx,tr[1].sub0);
    mx = max (mx,tr[1].sub1);
    mx = max (mx,tr[1].suf0);
    mx = max (mx,tr[1].suf1);

    cout << mx << "\n";
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


    // cin >> testcase;

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

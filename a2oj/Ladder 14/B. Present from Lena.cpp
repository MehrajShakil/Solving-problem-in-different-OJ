///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME
///   ALLAH save us from COVID-19.Amin.

///   █▀█─█──█──█▀█─█─█
///   █▄█─█──█──█▄█─█▄█
///   █─█─█▄─█▄─█─█─█─█

///   كُلُّ نَفْسٍ ذَآئِقَةُ الْمَوْت
///   Every soul shall taste death.


///   Author : Md Mehraj Hossain
///   Tag :

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp> //order_of_key return number of elements less than x, find_by_order return index (pointer use kora lgbe)

using namespace std;
using namespace __gnu_pbds;

#define ull      unsigned long long
#define ll       long long
#define ld       long double
#define pb       push_back
#define MOHAMMAD ios::sync_with_stdio(0);cin.tie(0);
#define ses      "\n"
#define all(x)   (x).begin(), (x).end()
#define pi       2*acos(0.0)
#define AE       cout << fixed << setprecision(10);

string digit="0123456789";
string small="abcdefghijklmnopqrstuvwxyz";
string capital="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

const ll MAXN=1e7+1;
const ll MOD = 1e9+7;

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)
        return 1;
    if(e%2==0)
    {
        ll t=bigmod(p,e/2,M);
        return (T)((t*t)%M);
    }
    return (T)((ll)bigmod(p,e-1,M)*(ll)p)%M;
}

template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);   // when M is prime;
}

typedef tree< ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

/// Fast read.
template<class T>inline bool read(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')
            sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}


//***********************************************  The END **********************************************************************************************************************************

/////////////////////////////////////////////////////////////////////////////

ll grid[20][20];

////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main()
{

    /// MOHAMMAD

    ll n ;
    cin >> n;
    ll tot = (2*n)+1;
    for ( ll i = 0 ; i<=n ; ++i )
    {
        grid[i][tot/2] = i;
        ll lf = i-1 , rg = i-1;
        for ( ll left = tot/2 - 1 ; left>=0 ; left-- ){
             grid[i][left] =  lf--;
        }
        for ( ll right = tot/2 + 1 ; right<tot ; right++ ){
             grid[i][right] =  rg--;
        }
    }
    ll k = n+1;
    for ( ll i = n-1 ; i>=0 ; i-- )
    {
        grid[k][tot/2] = i;
        ll lf = i-1 , rg = i-1;
        for ( ll left = tot/2 - 1 ; left>=0 ; left-- ){
             grid[k][left] =  lf--;
        }
        for ( ll right = tot/2 + 1 ; right<tot ; right++ ){
             grid[k][right] =  rg--;
        }
        ++k;
    }
    ll z = 0;
    for ( ll i = 0 ; i<tot ; ++i ){
         for ( ll j = 0 ; j<tot ; ++j ){
            if(!z and grid[i][j]==0){
                 cout << grid[i][j];
                z++;
            }
            else if(grid[i][j]>=0){
              cout << " " << grid[i][j];
                if(grid[i][j]==0) z++;
            }
            else {
                if(z<=1 and i>0 and i<tot-1) cout << "  ";
                else if(z<1) cout << "  ";

            }
         }
         cout << '\n';
         z = 0;
    }



}

/*




  Alhamdulillah
*/


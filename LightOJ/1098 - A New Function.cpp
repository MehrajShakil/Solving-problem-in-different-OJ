
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp> //order_of_key return number of elements less than x, find_by_order return index (pointer use kora lgbe)

using namespace std;
using namespace __gnu_pbds;

#define ull    unsigned long long
#define ll     long long
#define ios    ios::sync_with_stdio(0);cin.tie(0);
#define ses    "\n"
#define all(x) (x).begin(), (x).end()
//#define INF   ((int)2e18)
#define ii pair<ll, ll>

string digit="0123456789";
string small="abcdefghijklmnopqrstuvwxyz";
string capital="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

const int N=1e6+5;
const ll M=1e18;

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

struct Edge
{
    int u, vv;
    bool operator<(Edge const& other)
    {
        return vv > other.vv;
    }
}; // eta joss jinis.krsukal er jnno and sort 1 out of 3 or more er jnno better


//***********************************************  The END **********************************************************************************************************************************


/////////////////////////////////////////////////////////////////////////////
/*
pattern of divisors ::

///Thanks Kazi Mahbubur Rahman vai.I collect the source form him.

   N = 16
N  : 2  3  4  5  6  7  8
--------------------------------
1  -
2  -
3  -
4  - 2**  (d(4)=1+2).
5  -
6  - 2  3
7  -
8  - 2     4
9  -    3**       (d(9)=1+2)
10 - 2        5
11 -
12 - 2  3  4     6
13 -
14 - 2              7
15 -    3     5
16 - 2     4**         8   (d(16)=3+2)

 ///They are also called perfect number. There is a magic also that only, perfect number has odd number of divisors.

In right edge divisors are 2, 3, 4, 5, 6, 7, 8. It starts at N = 4. Notice it starts from divisor 2 and ends at 16/2 = 8.
Remaining divisors '2' located underneath the top 2 in a straight line.
Sum += 2+3+4+5+6+7+8
Sum += (8-2)*2

Then, Another divisors are 3, 4, 5. It starts at N = 9. Notice it starts from divisor '3' and ends at 16/3 = 5.
Remaining divisors '3' located underneath the second top 3 in a straight line.
Sum += 3+4+5
Sum += (5-3)*3

same to 4.

*/

////////////////////////////////////////////////////////////////////////////
//main function is here.........
int main()
{
   // ios
    ll t,tc=0;
    cin>>t;
    while(t--){
       ll n,sum=0;
       cin>>n;
       ll nn = sqrt(n);
       for(ll i=2;i<=nn;i++){
           ll x = n/i;
           ll xx = i;
           sum+=((x*(x+1))/2);
           sum-=((xx*(xx-1))/2);
           sum+=(x-i)*i;
       }
       //sum+=(n*(n+1))/2; that is need when we add 1 and that number also.
       //sum+=(n-1);
       cout<<"Case "<<++tc<<": "<<abs(sum)<<ses;
    }











}

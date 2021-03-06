// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

/// Author : Md Mehraj Hossain

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

const ll MAXN=1e18;
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

string solve()
{

    string num,numinbin,result[2]={"No","Yes"};
    cin >> num >> numinbin;
    vector<ll> bin;
    ll deci=0,ans=1;
    for(ll i=0; i<num.size(); i++)
    {
        if(num[i]=='.')
        {
         //  cout << deci << "\n ";
            bin.push_back(deci);
            deci=0;
        }
        else
        {
            if(num[i-1]!='.')
                deci*=10;
            deci+=num[i]-'0';
        }
    }
    bin.push_back(deci);

    ll now=1,part=3,tot=0;

    for(ll i=numinbin.size()-1; i>=0; i--)
    {
        if(numinbin[i]=='.')
        {
            //cout << tot << '\n';
            if(bin[part]!=tot)
            {
                ans=0;
                break;
            }
            part--;
            now=1;
            tot=0;
            continue;
        }
        else
        {
            if(numinbin[i]=='1')
                tot+=now;
        }
        now*=2;
    }
    if(bin[part]!=tot)
    {
        ans=0;
    }
  return result[ans];
}


////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main()
{
    //ios
    ll t,tc=0;
    cin >> t;
    while(t--)
    {
        cout << "Case "<< ++tc << ": " <<  solve() << '\n';
    }
}

/*



  Alhamdulillah
*/

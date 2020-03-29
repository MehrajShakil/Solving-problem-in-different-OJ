
//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Allah amader korona virus theke rokkha korun.Amin.

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
#define ses   "\n"
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

/////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
//main function is here.........
int main()
{

    ios
    char ch1;
    int h1,m1,h2,m2,avg1;
    cin>>h1>>ch1>>m1;
    cin>>h2>>ch1>>m2;


    int d = (60-m1)+m2;
    int x = 60*(h2-(h1+1));
    int sum = (x+d)/2;
    //cout<<sum<<ses;
    for(int i=1; i<=sum; i++)
    {

        if(m2!=0)
        {
            m2--;
        }
        else
        {
            h2--;
            m2=59;
        }


    }
    if(h2>9 && m2>9)
        cout<<h2<<":"<<m2;
    else if(h2<10 && h2 !=0 && m2>9)
        cout<<"0"<<h2<<":"<<m2;
    else if(h2>9 && m2 !=0 && m2<10)
        cout<<h2<<":"<<"0"<<m2;
    else if(h2<10 && m2 !=0 && h2 !=0 && m2<10)
        cout<<"0"<<h2<<":"<<"0"<<m2;
    else  if(h2==0 && m2<10)
    {
        cout<<"00"<<":"<<"0"<<m2;
    }
    else  if(h2==0 && m2>9)
    {
        cout<<"00"<<":"<<m2;
    }
    else  if(h2>9 && m2==0)
    {
        cout<<h2<<":"<<"0"<<m2;
    }
    else  if(h2<10 && m2==0)
    {
        cout<<"0"<<h2<<":"<<"00";
    }
}


/*


*/



//Alhamdulillah

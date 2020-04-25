                                            //BISMILLAHIR RAHMANIR RAHEEM
                                                //ALLAH IS WATCHING ME

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;

#define ull    unsigned long long
#define ll    long long
#define ios    ios::sync_with_stdio(0);cin.tie(0);
#define ses   "\n"

string digit="0123456789";
string small="abcdefghijklmnopqrstuvwxyz";

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

/////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////

//main function is here.........

int main()
{
    //ios
 ll n,c;
 cin>>n>>c;
 ll arr[n];
 for(ll i=0;i<n;i++)cin>>arr[i];
 ll mx=-1;
 for(ll i=0;i+1<n;i++){
    if(arr[i]>arr[i+1]){
        mx=max(arr[i]-arr[i+1]-c,mx);
    }
 }
 cout<<max(mx,(ll)0);
}



//Alhamdulillah

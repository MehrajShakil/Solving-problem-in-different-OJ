
                                            //BISMILLAHIR RAHMANIR RAHEEM
                                                //ALLAH IS WATCHING ME

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█
                                 //****************************************************
                                 //**          Date : 14/02/2020(time is over)       **
                                 //**              Love is not for a day             **
                                 //**                                                **
                                 //****************************************************
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

const int N=1e6+5;
const int MOD=1e9+7;

/////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main(){
    ll tc;
    cin>>tc;
    vector<double> arr(1000005);
    arr[0]=0;
    for(ll i=1;i<=1000000;i++){
                arr[i]=arr[i-1]+log(i);
    }
    for(ll i=1;i<=tc;i++){
         ll n,base;
         cin>>n>>base;
         cout<<"Case "<<i<<": "<<int(arr[n]/(log(base)))+1<<ses;
    }
}




//Alhamdulillah

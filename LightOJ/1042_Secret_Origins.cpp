
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
    for(ll i=1;i<=tc;i++){
     ll n;
     cin>>n;
     vector<ll> v;
     while(n>=2){
                v.push_back(n%2);
                n/=2;
     }
     v.push_back(n);
     v.push_back(0);
     reverse(v.begin(),v.end());
     next_permutation(v.begin(),v.end());
    ll ans=0,pos=0;
    for(ll i=v.size()-1;i>=0;i--){
                if(v[i]){
                                ans|=(1LL<<pos);
                }
                pos++;
    }
    cout<<"Case "<<i<<": "<<ans<<ses;
    }
}




//Alhamdulillah

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

const int N=1e6+5;
const int M=(int)1e9+7;


/////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
//main function is here.........
int main(){
 ll t,tc=0;
 cin>>t;
 while(t--){
               ll n,m;
               cin>>n>>m;
               ll ans=n*m;
               if(n==1 || m==1)ans=max(n,m);
               else if(n==2 || m==2){
                ll mx = max(n,m),extra;
                ans = mx/4;
                if(mx%4<3)extra=mx%4;
                else extra=2;
                ans*=4;
                ans+=(extra*2);
               }
               else{
                ans=((m*n)+1)/2;
               }
                cout<<"Case "<<++tc<<": "<<ans<<ses;
 }
}





//Alhamdulillah

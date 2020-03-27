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
vector< ll > v(1001),pos(1001);

ll divisor(ll n){
                ll cnt=0;
for(ll i=1;i<=sqrt(n);i++){
                if(n%i==0 && (n/i)!=i)cnt+=2;
                else if(n%i==0)cnt++;
}
return cnt;
}

bool check(ll i,ll j){
if(v[i]==v[j])return i>j;
return v[i]<v[j];
}
////////////////////////////////////////////////////////////////////////////
//main function is here.........
int main(){
ll tc;
cin>>tc;
for(ll i=1;i<=1000;i++){
               v[i]=divisor(i);
               pos[i]=i;
}
sort(pos.begin()+1,pos.end(),check);
for(ll i=1;i<=tc;i++){
                ll n;
                cin>>n;
                cout<<"Case "<<i<<": "<<pos[n]<<ses;

}
}





//Alhamdulillah

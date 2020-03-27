
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
                ll n,row,col;
                cin>>n;
                ll root=ceil((double)sqrt(n));
                ll r=(root*root)-(root-1);
                if(root&1){
                if(n>=r){
                       row=root;
                       col=root-(n-r);
                }
                if(n<r){
                       col=root;
                       row=root-(r-n);
                }
                }
                else{
                     if(n>=r){
                       col=root;
                       row=root-(n-r);
                           }
                if(n<r){
                       row=root;
                       col=root-(r-n);
                }
                }
                cout<<"Case "<<++tc<<": "<<col<<" "<<row<<ses;
 }
}





//Alhamdulillah

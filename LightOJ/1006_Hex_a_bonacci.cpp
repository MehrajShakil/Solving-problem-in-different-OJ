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
 int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        int arr[10001]={0};
        scanf("%d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &n);
        for(ll i=6;i<=n;i++){
                arr[i]=((arr[i-1]%10000007)+(arr[i-2]%10000007)+(arr[i-3]%10000007)+(arr[i-4]%10000007)+(arr[i-5]%10000007)+(arr[i-6]%10000007))%10000007;
        }
        printf("Case %d: %d\n", ++caseno, arr[n] % 10000007);
    }
    return 0;
}





//Alhamdulillah

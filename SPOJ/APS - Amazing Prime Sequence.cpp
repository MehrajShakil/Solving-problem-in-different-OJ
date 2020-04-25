
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 1e7+1;

long long f[MAXN];
long long factor[MAXN];
void sieve()
{


    for(long long i=2; i<MAXN; i++)
    {
        if(factor[i]==0)
        {
            factor[i]=i;
            for(long long j=i*i; j<MAXN; j+=(i))
            {
               if(factor[j]==0)factor[j]=i;
            }
        }
        f[i] = factor[i] + f[i-1];
    }

}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    sieve();
    f[0]=f[1]=0;



    long long t,n;

    cin >> t;

    while(t--){
        cin >> n;
        cout << f[n]<<'\n';
    }



}

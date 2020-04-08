
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

#include<bits/stdc++.h>
using namespace std;
#define ios    ios::sync_with_stdio(0);cin.tie(0);
using ll = long long;
const int N =99998953;


ll primes[3200000];   /// mx >> 5 == mx/(2^5).it's called right shift.


bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
ll Set(ll N,ll pos)
{
    return N=N | (1<<pos);
}


void sieve()
{

    ll sqrtN = sqrt(N);

    for(ll i=3; i<=sqrtN; i+=2)
    {
        // cout<<i<<" "<<Check(primes[i>>5], i&31)<<endl;
        if(Check(primes[i>>5], i&31)==0)              // i&31 == i%32.
        {
            for(ll j = i*i ; j<=N; j+=(i<<1))
            {
                //cout<<j<<" "<<Set(primes[j>>5],j&31)<<endl;
                primes[j>>5]=Set(primes[j>>5],j&31);
            }
        }
    }
    puts("2");
    ll mod=1;
    for(ll i=3; i<=N; i+=2)
    {
        if(Check(primes[i>>5],i&31)==0)
        {
            mod++;
            if(mod%100==1)
            {
                cout<<i<<endl;
            }
        }
    }
}


int main()
{
    sieve();
    return 0;

}


//Alhamdulillah

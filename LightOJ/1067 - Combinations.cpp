
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// Allah save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 1000003;
const ll MAXN = 1000001;

//Fermat's little Theorem says : (a/b) mod m == ((a mod m ) * ((b^m-2) mod m)) mod m when m is prime
ll Factorial[MAXN];
ll inverseOfFactorial[MAXN];


// This function is use for find (b ^(m-2)) mod m.
ll binpow(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


// this function done modular multiplicative inverse task.
ll modInv(int base)
{

    return binpow(base, mod - 2, mod);

}


// pre-compute....
void init() {

    Factorial[0] = 1;
    inverseOfFactorial[0] = modInv(Factorial[0]);

    for(ll i=1;i<MAXN;i++) {
        Factorial[i] = 1LL * i * Factorial[i - 1] % mod;
        inverseOfFactorial[i] = modInv(Factorial[i]);
    }

}
// This function give us nCr.
ll nCr(ll n, ll r) {
    if(r > n) return 0;
    ll ans = Factorial[n];
    ans = 1LL * ans * inverseOfFactorial[r] % mod;
    ans = 1LL * ans * inverseOfFactorial[n - r] % mod;
    return ans;
}

int main(){

     init();
     ll t,tc=0;
     cin>>t;
     while(t--){
        ll n,r;
        cin>>n>>r;
        cout<<"Case "<<++tc<<": "<<nCr(n,r)<<'\n';
     }


}


// Alhamdulillah.


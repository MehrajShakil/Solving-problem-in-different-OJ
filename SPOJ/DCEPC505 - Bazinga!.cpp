// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

/// Author : Md Mehraj Hossain

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MAXN=1e7;
vector<ll> ans,prime;
bitset<MAXN> bs;

void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=4; i<=MAXN; i+=2)
        bs[i]=0;
    prime.push_back(2);
    for(ll i=3; i<=MAXN; i+=2)
    {
        if(bs[i])
        {
            prime.push_back(i);
            for(ll j=i*i; j<=MAXN; j+=i<<1)
            {
                bs[j]=0;
            }
        }
    }


}

void solve()
{
    for(ll i=0; i<prime.size() ; i++)
    {
        for(ll j=i+1; j<prime.size() ; j++)
        {
            if(prime[i]*prime[j]>=11000000)break;
            ans.push_back(prime[i]*prime[j]);
        }
    }
}

int main()
{
    sieve();
    solve();
    sort(ans.begin(),ans.end());
    ll t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << ans[n-1] << '\n';
    }
}

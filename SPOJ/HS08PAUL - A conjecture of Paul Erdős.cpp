
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;

using ll =long long;
const ll MAXN = 1e7;


bitset<MAXN+1> bs;

void sieve()
{

    bs.set();
    bs[0]=bs[1]=0;

    for(ll i=4; i<=MAXN; i+=2)
        bs[i]=0;

    for(ll i=3; i<=MAXN; i+=2)
    {
        if(bs[i])
        {
            for(ll j =i*i; j<=MAXN; j+=i<<1)
            {
                bs[j]=0;
            }
        }
    }
}

int main()
{
    sieve();
    map<ll,ll> mp;
    vector<ll> v;
    for(ll i=1; i*i<=MAXN; i++)
    {
        for(ll j=1; (i*i)+(j*j*j*j)<=MAXN; j++)
        {
            ll x =(i*i) + (j*j*j*j);
            if(x<=MAXN and bs[x] and !mp[x]){
                v.push_back(x);
                mp[x]=1;
            }
        }
    }
    sort(v.begin(),v.end());
    ll t;
    cin >> t;
    while(t--)
    {

        ll n;
        cin >> n;

        cout << upper_bound(v.begin(),v.end(),n)-v.begin() << '\n';



    }
}

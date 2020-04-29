// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// Allah save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

#include<bits/stdc++.h>
using namespace std;
using ll = long long signed;

const ll mod = 1000000007;

ll sum(ll arr[],ll n)
{
    ll ans=0;
    for(ll i=0; i<n; i++)
    {
        if(0<(arr[i]-i))
        {
            ans+=(arr[i]-i);
            ans%=mod;
        }
        else
            break;
    }
    return ans;
}

int main()
{

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0; i<n; i++)
            cin>>arr[i];
        sort(arr,arr+n,greater<int>());

        ll ans = sum(arr,n);
        cout<<ans<<'\n';
    }
}

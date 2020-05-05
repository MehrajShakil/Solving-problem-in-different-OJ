#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void  Factor(ll n ,map<ll,ll> &mp)
{
    ll freq=0;
    while(n%2==0)
    {
        n/=2;
       freq++;
    }
    mp[2]=max(freq,mp[2]);

    for(ll i=3; i*i<=n; i+=2)
    {
        freq=0;
        while(n%i==0)
        {
            n/=i;
            freq++;
        }
        mp[i]=max(mp[i],freq);
    }

    if(n>1)
        mp[n]=1;
}

int main()
{
    int t,k;
    cin>>t;

    for(int k=1; k<=t; k++)
    {
        map<ll,ll> mp;
        ll a,b,l,i;
        cin>>a>>b>>l;
        if(l%a!=0 || l%b!=0)
        {
            cout<<"Case "<<k<<": "<<"impossible\n";
            continue;
        }
        else
        {
            ll ans=1;
            Factor(a,mp);
            Factor(b,mp);
            for(auto f : mp)
            {
                ll mul = f.first ,cnt=0;
                while(l%mul==0){
                      l/=mul;
                      cnt++;
                }
                if(cnt> (f.second)){
                    for(ll i=0;i<cnt;i++){
                                ans*=mul;
                    }
                }
            }

            for(ll i=2;i*i<=l;i++){
                while(l%i==0){
                      l/=i;
                      ans*=i;
                }
            }
            if(l>0)ans*=l;
            cout<<"Case "<<k<<": "<<ans<<endl;
        }
    }
}

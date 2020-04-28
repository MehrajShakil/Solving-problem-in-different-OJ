#include<bits/stdc++.h>
using namespace std;
using ll =long long;

map<ll,ll> mp;

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

void Factor(ll n)
{
    ll nn=n;

    while(n%2==0)
        n/=2;
    mp[2]=1;
    for(ll i=3; i*i<=nn; i+=2)
    {
        while(n%i==0)
        {
            n/=i;
            mp[i]=1;
        }
    }

    if(n>1)
        mp[n]=1;
}

int main()
{
    ll p,n,r;
    while(cin >> p >> n)
    {
        if(p==0 and n==0)
            break;
        Factor(p-1);
        vector<ll> v;
        for(auto it : mp)
        {
            v.push_back((p-1)/it.first);
        }

        while(n--)
        {
            cin >> r;
            int ans=1;
            for(ll i=0; i<v.size(); i++)
            {
                if(binpow(r,v[i],p)==1)
                {
                    ans=0;
                    break;
                }
            }
            if(ans)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        mp.clear();
    }
}

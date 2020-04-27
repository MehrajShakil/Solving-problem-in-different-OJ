#include<bits/stdc++.h>
using namespace std;

using ll =long long;
map<ll,ll> mp;

void Factor(ll n)
{

    ll nn=n;
    while(n%2==0)
    {
        n/=2;
        mp[2]++;
    }
    for(ll i=3; (i*i)<=nn; i+=2)
    {
        while(n%i==0)
        {
            n/=i;
            mp[i]++;
        }
    }
    if(n>1)
    {
        mp[n]++;
    }

}


int main()
{
    ll n;
    while(cin >> n)
    {
        if(n==0)
            break;

        Factor(n);
        for(auto it : mp)
        {
            cout<<it.first<<'^'<<it.second<<" ";
        }
        cout<<'\n';
        mp.clear();
    }


}

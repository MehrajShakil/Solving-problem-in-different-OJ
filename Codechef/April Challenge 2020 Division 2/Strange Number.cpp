#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const ll MAXN = 1e7;
ll freq=0,k;
bool factor(ll n)
{
    ll nn=n;
    while(n%2==0)
    {
        n/=2;
        freq++;
    }

    for(ll i=3; i*i<=nn; i+=2)
    {
        while(n%i==0)
        {
            n/=i;
            freq++;
        }
    }
    if(n>1)
        freq++;
    return freq>=k;
}



int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n >> k;

        cout<<factor(n)<<'\n';
        freq=0;
    }

}

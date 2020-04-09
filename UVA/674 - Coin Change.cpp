#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int coins[5]= {50,25,10,5,1};

int main()
{
    ll n;
    while(cin>>n)
    {
        ll noways[n+1]= {0};
        noways[0]=1;

        for(ll i=0; i<5; i++)
        {
            for(ll j=1; j<=n; j++)
            {
                if(j>=coins[i])
                    noways[j]+=noways[j-coins[i]];
            }
        }
        cout<<noways[n]<<'\n';
    }
}

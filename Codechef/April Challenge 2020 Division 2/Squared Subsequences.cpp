#include<bits/stdc++.h>
using namespace std;

using ll =long long;
unordered_map<ll, ll > prevsum;

ll findsubarray(ll arr[], ll n, ll k)
{
    ll cursum=0,res=0;

    for(ll i=0; i<n; i++)
    {
        cursum+=arr[i];
        if(cursum==k)
        {
            res++;
        }
        if(prevsum[cursum-k]!=0)
        {
            res+=prevsum[cursum-k];
        }
        prevsum[cursum]++;

    }
    return res;
}


int main()
{

    ll t;
    cin >> t;
    while(t--)
    {
        prevsum.clear();
        ll n;
        cin >> n;
        ll arr[n];
        for(ll i=0; i<n; i++)
            cin >> arr[i];

        for(ll i=0; i<n; i++)
        {
            if(arr[i]%4==0)
            {
                arr[i]=2;
            }
            else if(arr[i]%2==0)
            {
                arr[i]=1;
            }
            else
                arr[i]=0;
        }

        cout <<(n*(n+1)/2) - findsubarray(arr,n,1LL)<<'\n';
    }
}


// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// Allah save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

#include<bits/stdc++.h>
using namespace std;
using ll = long long signed;
const ll MAXN = 5000000;
vector<int> phi(MAXN + 1);
unsigned long long sum[MAXN+1];

void phi_1_to_n()
{
    ll n=MAXN;
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
int main()
{
    phi_1_to_n();

    sum[1]=0;
    for(ll i=2; i<=5000000; i++)
    {
        sum[i]=phi[i];
        sum[i]*=phi[i];
        sum[i]+=sum[i-1];
    }
    ll t,tc=0;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<"Case "<<++tc<<": "<<sum[b]-sum[a-1]<<'\n';
    }
}

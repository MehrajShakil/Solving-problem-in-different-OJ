// C++ program to implement bitwise Sieve
// of Eratosthenes.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 1e8;
long double harmonic[100001];
ll ind=1000;
int main()
{

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    harmonic[0]=0;
    long double nth=0;
    for(ll i=1; i<=MAXN ; i++)
    {
        nth+=(long double)(1.0/i);
        if(ind==i)
        {
            harmonic[i/1000]=nth;
            ind+=1000;
             //cout << i/1000 << endl;
            // cout << ind << endl;
        }
    }

    ll t,tc=0;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;

        long double nth = harmonic[(n/1000)];

        for(ll i = ((n/1000)*1000) +1 ; i <=n ; i++)
        {
            nth+=(1.0/i);
        }

        cout << fixed;
        cout <<  setprecision(10);
        cout << "Case " << ++tc << ": " << nth << '\n';
    }

}

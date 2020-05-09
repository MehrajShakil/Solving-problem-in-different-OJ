// C++ program to implement bitwise Sieve
// of Eratosthenes.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAXN  = 1e6;



ll phi(ll n)
{
    ll total = n;
    for(ll i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
                n/=i;
            total-=(total/i);
        }
    }
    if(n>1)
        total-=total/n;
    return total;
}

void solve()
{
    ll n;
    cin >> n;
    ll total = n*(n+1)/2;
    if(n<=2)
        cout << 0 << '\n';
    else
    {
        cout << (total - phi(n)/2*n)-n << '\n';
    }
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
/*
Explanation ::
observation #1: when n>2 phi(n) is even.
observation #2: we know gcd(a,n)=gcd(n-a,n).
                so,if gcd(a,n)=1 then gcd(a-n ,n)=1.
                From this we can ensure that coprime r stay pairwise.
                n contain phi(n)/2 pairs. and every pair sum=n.
                so sum = n*phi(n)/2.
reference : forthright48.
*/



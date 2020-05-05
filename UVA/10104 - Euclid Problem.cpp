
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;

using ll =long long;

void ex_gcd(ll a,ll b, ll&x, ll&y)
{
    x=1,y=0;
    ll x1=0,y1=1,a1=a,b1=b;
    while(b1)
    {
        ll q=a1/b1;
        tie(x,x1) = make_tuple(x1,x-q*x1); // now x = x1 and x1 = x-q*x1;
        tie(y,y1) = make_tuple(y1,y-q*y1);
        tie(a1,b1) = make_tuple(b1,a1-q*b1);
    }
    cout << x << " " << y  << " " << a1 << '\n';
}

int main()
{

    ll a,b,x,y;

    while(cin >> a >> b){
    ex_gcd(a,b,x,y);
    }
}

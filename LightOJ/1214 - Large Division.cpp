
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// Allah save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

#include<bits/stdc++.h>
using namespace std;
using ll = long long signed;

bool solve(string a, ll b)
{

    if(b<0)
    {
        b*=(-1);
    }
    ll rem = 0;
    for(ll i=0; i<a.size(); i++)
    {
        if(a[i]=='-')
            continue;
        rem = ((rem*10) + (a[i]-'0'))%b;
    }

    return (rem==0) ? 1 : 0;
}


int main()
{
    ll t,tc=0;
    cin>>t;
    while(t--)
    {
        string a;
        ll b;
        cin>>a>>b;
        if(solve(a,b))
            cout<<"Case "<<++tc<<": "<<"divisible"<<'\n';
        else
            cout<<"Case "<<++tc<<": "<<"not divisible"<<'\n';
    }
}

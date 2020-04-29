// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// Allah save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

#include<bits/stdc++.h>
using namespace std;
using ll = long long signed;

const ll mod = 1000000007;

bool sum(string s)
{
    bool sha_kil=true;
    for(ll i=0; i<s.size()-1; i++)
    {
        if(s[i]=='1' && (i+6)<s.size())
        {
            if(s.substr(i+1,5)!="00000")
            {
                sha_kil=false;
                break;
            }
        }
        if(s[i]=='1' && (i+6)>=s.size())
        {
            for(ll j=i+1; j<s.size(); j++)
            {
                if(s[j]=='1')
                    sha_kil=false;
            }
            break;
        }
    }
    return sha_kil;
}

int main()
{

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        for(ll i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            if(x)
                s+='1';
            else
                s+='0';
        }
        if(sum(s))
        {
            cout<<"YES"<<'\n';
        }
        else
            cout<<"NO"<<'\n';
    }
}

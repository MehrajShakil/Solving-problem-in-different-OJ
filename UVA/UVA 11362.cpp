
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

bool solve(vector<string > v)
{

    bool sha_kil=true;

    sort(v.begin(),v.end());
    string s = v[0],ss;

    for(ll i=1; i<v.size(); i++)
    {
        ss=v[i];
        if(ss.substr(0,s.size())==s)
        {
            sha_kil=false;
            break;
        }
        else
        {
            s = v[i];
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
        vector<string> v;
        while(n--)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }

        if(solve(v))
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }

}

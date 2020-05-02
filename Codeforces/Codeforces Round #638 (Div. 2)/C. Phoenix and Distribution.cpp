// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

/// Author : Md Mehraj Hossain

#include<bits/stdc++.h>
using namespace std;

using ll =long long;

int main()
{

    ll t,n,k,pp=1;
    cin >> t;
    while(t--)
    {
        string s,ans="";
        cin >> n >> k;
        cin >> s;

        sort(s.begin(),s.end());
        map<char,int> mp,done;
        if(k==1)
        {
            cout << s << '\n';
            continue;
        }
        else if(s[0]!=s[k-1])
        {
            cout << s[k-1] << '\n';
        }
        else
        {
            ans = s[k-1];
            for(int i=k-1; i<n; i++)
            {
                mp[s[i]]=1;
                if(i>=k)
                    done[s[i]]=1;
            }
            if(mp.size()>2 || done.size()>=2)
            {
                for(int i=k; i<n; i++)
                {
                    ans+=s[i];
                }
            }
            else if(mp.size()==1 || done.size()==1)
            {
                int tot = n-k;
                int add  =tot/k;
                if(tot%k!=0)
                    add++;
                for(int i=k; i<k+add; i++)
                    ans+=s[i];
            }

            cout << ans << '\n';
        }
    }
}

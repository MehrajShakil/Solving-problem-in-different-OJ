
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {

        int n,o=0,t=0;
        cin >> n;

        for(int i =1; i<n/2 ; i++)
        {
            o+=1<<i;
        }
        for(int i =n/2; i<n ; i++)
        {
            t+=1<<i;
        }
        o+=1<<n;

        cout << abs(o-t) << '\n';
    }

}

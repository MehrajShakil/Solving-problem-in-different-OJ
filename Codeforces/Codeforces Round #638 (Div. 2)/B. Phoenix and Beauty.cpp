
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

bool check(int arr[], int n,int k, set<int > &s)
{

    for(int i=0; i<n; i++)
    {
        s.insert(arr[i]);
    }
    return s.size()<=k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, kk;
        cin >> n >> kk;
        int arr[n];
        set<int> s;
        for(int i =0; i<n; i++)
            cin >> arr[i];
        if(!check(arr, n, kk,s))
        {
            cout << -1 << '\n';
        }
        else
        {
            for( int i =1 ; i<=n ; i++)
            {
                if(s.size()==kk)break;
                if(s.find(i)==s.end())
                {
                    s.insert(i);
                }

            }
            int x = s.size()*n ;

            cout << x << '\n';

            while(x)
            {
                for(auto it : s)
                {
                    cout << it << " ";
                }
                x-=kk;
            }
            cout << '\n';
        }


    }

}

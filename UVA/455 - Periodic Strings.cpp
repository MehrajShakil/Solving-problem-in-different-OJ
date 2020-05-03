// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

/// Author : Md Mehraj Hossain

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int>compute_prefix(string pattern)
{

    int n = pattern.size();
    vector<int> prefix(n+1);
    prefix[0]=0;
    int k=0;
    for(int i =1; i<n; i++)
    {
        while(k>0 and pattern[k]!=pattern[i])
            k=prefix[k-1];

        if(pattern[i]==pattern[k])
            k++;
        prefix[i]=k;
    }
    return prefix;
}

int KMP(string text)
{
    vector <int> prefix = compute_prefix(text);
    int cur = text.size();
    int n = text.size();
    while(cur){
         cur = prefix[cur-1];
        if(n%(n-cur)==0){
                return n-cur;
        }
    }
}

int main()
{

    int  t;
    cin >> t;

    while(t--){
    string text;
    cin >> text;

    cout << KMP(text) << '\n';

    if(t)cout << '\n';
    }
}

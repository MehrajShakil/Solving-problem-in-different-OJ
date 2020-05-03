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

int KMP(string text,string pattern)
{

    vector <int> prefix = compute_prefix(pattern);
    int match_pos=0;

    text+=text;
    int mn=0;
    for(int i=0; i<text.size(); i++)
    {
        while(match_pos>0 and pattern[match_pos]!=text[i])
            match_pos=prefix[match_pos-1];

        if(pattern[match_pos]==text[i])
            match_pos++;
        if(match_pos==pattern.size())
        {
            mn = i;
            match_pos=prefix[match_pos-1];
            //cout << mn << endl;
        }
    }
    return mn;
}


int main()
{

    int n;
    cin >> n;

    string text, pattern;
    cin >> text >> pattern;
    int mn = KMP(text,pattern);
    if(mn==0) cout << -1 <<'\n';
    else if(mn==n-1) cout << 0 <<'\n';
    else cout << n- (mn+1-n)  <<'\n';

}

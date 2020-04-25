
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+1;

bitset<MAXN> bs;

vector<int> primediv(MAXN,0),lucky;

void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;

    for(int i=2; i<MAXN; i++)
    {
        if(bs[i])
        {
            for(int j=i*2; j<MAXN; j+=i)
            {
                primediv[j]++;
                bs[j]=0;
            }
        }
    }
}

int main()
{
    sieve();

    for(int i=1; i<MAXN; i++)
    {
        if(primediv[i]>=3)
        {
            lucky.push_back(i);
        }
    }

    int q;
    cin>>q;
    while(q--){
         int n;
         cin >> n;
         cout<<lucky[n-1]<<'\n';
    }

}

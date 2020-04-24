// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;

const long long MAXN = 5e3;

bitset<MAXN> bs;
vector<int> prime;

void sieve()
{
    bs.set();
    prime.push_back(2);
    bs[0]=bs[1]=0;
    for(int i=2 ; i<=MAXN ; i+=2)
        bs[i]=0;

    for(int i=3 ; i*i<=MAXN ; i+=2)
    {
        if(bs[i])
        {
            for(int j=i*i ; j<=MAXN ; j+=(i+i))
            {
                bs[j]=0;
            }
        }
    }
    for(int i=3 ; i<=MAXN ; i+=2)
    {
        if(bs[i])
        {
            prime.push_back(i);
        }
    }

}

void FACTOR(int n)
{

    int nn=n;
    cout<<1;
    for(int i = 0; i<prime.size() && (prime[i]*prime[i])<=n ; i++)
    {
        int p = prime[i];
        if(p>nn)
            break;
        while(nn%p==0)
        {
            nn/=p;
            cout<<" x "<<p;
        }
    }

    if(nn>1)
    {
        cout<<" x "<<nn;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();
    int n;
    while(cin >> n)
    {
        FACTOR(n);
        cout<<'\n';
    }



}

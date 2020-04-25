
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 1e4;


bitset<10000010> bs;
vector<int> primes;

void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;
    primes.push_back(2);

    for(int i=2; i<=MAXN ; i+=2)
        bs[i]=0;

    for(int i=3; i<=MAXN ; i+=2)
    {
        if(bs[i])
        {
            primes.push_back(i);
            for(int j = i*i ; j<=MAXN ; j+=(i+i))
            {
                bs[j]=0;
            }
        }
    }
}

int pref[(int)1e7+1]= {0};

void Factor(int n)
{
    int nn=n;
    for(int i=0; i<primes.size() && primes[i]*primes[i]<=nn ; i++)
    {
        int p = primes[i],freq=0;
        if(p>n)
            break;
        while(n%p==0)
        {
            n/=p;
            freq=1;
        }
        if(freq)
            pref[p]++;
    }
    if(n>1)
        pref[n]++;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();

    long long n,x;
    cin >> n;

    for(long long i=0; i<n; i++)
    {
        cin>>x;
        Factor(x);
    }

    for(int i=1; i<=1e7 ; i++)
    {
        pref[i]+=pref[i-1];
    }

    long long q;
    cin >> q;

    while(q--)
    {
        long long l,r;
        cin >>  l >>r;

        if(l>=1e7)
            cout<<0<<endl;
        else if(r>1e7)
        {
            cout<<pref[(int)1e7]-pref[l-1]<<endl;
        }
        else
        {
            cout<<pref[r]-pref[l-1]<<endl;
        }

    }


}

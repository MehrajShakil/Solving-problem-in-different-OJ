
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6+1;

long long ans[MAXN],sz=0;
long long factor[MAXN]= {0},divisor[MAXN];
vector<int> v[MAXN];
void sieve()
{
    memset(divisor,0,sizeof divisor);
    for(int i =2 ; i<=100 ; i++)
    {
        int c = i*i*i;
        for(int j = c; j<MAXN ; j+=c)
        {
            divisor[j]=1;
        }
    }
    int    last=1;
    for(int j = 1; j<MAXN; j++)
    {
        if(divisor[j]==0)
        {
            ans[sz]=j;
            sz++;
            factor[j]=last;
            last++;
        }
        else
        {
            factor[j]=last;
        }
    }
}



int main()
{
    ///ios::sync_with_stdio(false);
    ///cin.tie(false);
    ///cout.tie(false);

    sieve();

    int t,tc=0;
    cin >>  t;
    while(t--)
    {
        int n;
        cin >> n;
        cout<<"Case "<<++tc<<": ";
        if(divisor[n])
            cout<<"Not Cube Free\n";
        else
        {
            cout<<factor[n]<<endl;
        }
    }



}

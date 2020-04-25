
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6+1;

long long f[MAXN];
long long factor[MAXN]= {0} ,divisor[MAXN]={0};
vector<int> v[MAXN];
void sieve()
{


for(int i=1;i<=MAXN;i++){
   for(int j=i;j<=MAXN;j+=i){
        divisor[j]++;
   }
}

    for(long long i=2; i<MAXN; i++)
    {
        if(v[i].size()==0)
        {
            for(long long j=i; j<MAXN; j+=(i))
            {
                v[j].push_back(i);
            }
        }
    }

}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    sieve();



    long long t,n,mark=1;

    for(int i=1; i<=1e6; i++)
    {
        int d = divisor[i];
        if(v[d].size()==2 and (v[d][0]*v[d][1])==d)
        {
            if(mark%9==0)
            {
                cout<<i<<endl;
                mark=1;
            }
            else
                mark++;
        }
    }




}

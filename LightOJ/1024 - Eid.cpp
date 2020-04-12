
// BISMILLAHIR RAHMANIR RAHEEM
// ALLAH IS WATCHING ME
// ALLAH save us from COVID-19.Amin.

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
const int base = 1e9;

#define pb push_back
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define EL printf("\n")

typedef vector<int> BigInt;

void Set(BigInt &a)
{
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
}

void Print(BigInt a)
{
    Set(a);
    printf("%d", (a.size() == 0) ? 0 : a.back());
    FORD(i,a.size()-2,0) printf("%09d", a[i]);
    EL;
}

BigInt Integer(string s)
{
    BigInt ans;
    if (s[0] == '-')
        return ans;
    if (s.size() == 0)
    {
        ans.pb(0);
        return ans;
    }
    while (s.size()%9 != 0)
        s = '0'+s;
    for (int i=0; i<s.size(); i+=9)
    {
        int v = 0;
        for (int j=i; j<i+9; j++)
            v = v*10+(s[j]-'0');
        ans.insert(ans.begin(),v);
    }
    Set(ans);
    return ans;
}

BigInt Integer(char c[])
{
    string s = "";
    FOR(i,0,strlen(c)-1) s = s + c[i];
    return Integer(s);
}

BigInt Integer(ll x)
{
    string s = "";
    while (x > 0)
        s = char(x%10+'0') + s, x /= 10;
    return Integer(s);
}

BigInt Integer(int x)
{
    return Integer((ll) x);
}

void operator >> (istream &in, BigInt &a)
{
    string s;
    getline(cin, s);
    a = Integer(s);
}

void operator << (ostream &out, BigInt a)
{
    Print(a);
}

BigInt operator * (BigInt a, BigInt b)
{
    Set(a);
    Set(b);
    BigInt ans;
    ans.assign(a.size()+b.size(), 0);
    FOR(i,0,a.size()-1)
    {
        ll carry = 0ll;
        for (int j=0; j<b.size() || carry > 0; j++)
        {
            ll s = ans[i+j] + carry + (ll)a[i]*(j<b.size()?(ll)b[j]:0ll);
            ans[i+j] = s%base;
            carry = s/base;
        }
    }
    Set(ans);
    return ans;
}

bitset<1000001> bs;
vector<ll> primes;

void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2; i<=1000000; i+=2)
        bs[i]=0;
    primes.pb(2);
    for(ll i=3; i<=1000000; i+=2)
    {
        if(bs[i])
        {
            primes.pb(i);
            for(ll j=i*i; j<=1000000; j+=(i+i))
            {
                bs[j]=0;
            }
        }
    }
}
map<ll,ll> mp;
void Factor(ll x)
{
    ll xx = x;
    for(ll i=0; i<primes.size() && primes[i]*primes[i]<=xx; i++)
    {
        if(primes[i]>x)
            break;
        ll freq=1;
        while(x%primes[i]==0)
        {
            x/=primes[i];
            freq*=primes[i];
        }
        mp[primes[i]]=max(mp[primes[i]],freq);
    }
    if(x>1){
        mp[x]=max(x,mp[x]);
    }

}

int main()
{
    //ios::sync_with_stdio(0);cin.tie(0);
    sieve();
    ll t,tc=0;
    cin>>t;
    while(t--)
    {
        mp.clear();
        ll n,x;
        cin>>n;
        while(n--)
        {
            cin>>x;
            Factor(x);
        }
        BigInt A,B;
        A = Integer(1);

        for(auto it=mp.begin();it!=mp.end();it++){
                ll k = it->second;
                B = Integer(k);
                A = A*B;
        }
       printf("Case %lld: ",++tc);Print(A);
      // EL;
    }
}


//Alhamdulillah.

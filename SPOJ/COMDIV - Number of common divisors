#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N = 1000000;
vector < ll > primes;
bitset<N+1> bs;

void sieve ( ){
	bs.set();
	bs[0]=bs[1]=0;
	primes.push_back ( 2 );
	for ( ll i = 4 ; i<=N ; i+=2 ) bs[i] = 0;
	
	for ( ll i = 3 ; i<=N ; i+=2 ){
		if ( bs[i] ){
			primes.push_back ( i );
			for ( ll j = i*i ; j<=N ; j+=(i<<1) ) bs[j] = 0;
		} 
	}
}

int main ( ){
	
     sieve ();
     
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);

     ll t , a , b;
     cin >> t;
     
     while ( t-- ){
     	
     	   cin >> a >> b;
     	   ll comdiv = 1;
     	   
     	   ll gcd = __gcd ( a , b );
     	
     	   for ( auto p : primes ){
     	   	    if ( p*p>gcd ) break;
     	   	   ll freq = 1;
     	   	    while ( gcd%p == 0 ){
     	   	    	gcd/=p;
     	   	    	freq++;
     	   	    }
     	   	    comdiv*=freq;
     	   }
     	   if(gcd>1)comdiv*=2LL;
     	   
     	   cout << comdiv << "\n";
     	   
     }
	
}


///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME
///   ALLAH save us from COVID-19.Amin.

///   Every soul shall taste death.

///   Tag ::

#include<bits/stdc++.h>
using namespace std;

#define AE        cout << fixed << setprecision(10);

using ll = long long;
using ld = double;

const ll N = 1e5+1;
const ll INF = 1e18;
const ll limit = (1LL<<64) - 1;
const ld EPS   = 1e-8;

ll BIT[N];

void update ( ll idx , ll val ) {
    while ( idx<N ){
       BIT[idx]+=val;
       idx+=(idx&-idx);
    }
}

ll query ( ll idx ){
   ll sum = 0;
   while ( idx > 0 ){
       sum+=BIT[idx];
       idx-=(idx&-idx);
   }
   return sum;
}


int main()
{
   /// ios::sync_with_stdio(0);
   /// cin.tie(0);
   /// cout.tie(0);

   int t , tc = 0;
   scanf ( "%d" , &t );

   while ( t-- ){
         printf("Case %d:\n",++tc);
         int n ,q , l , r , v;
         scanf ( "%d%d" , &n , &q );
         ll arr[n+1];
         for ( ll i = 1 ; i <= n ; ++i ) cin >> arr[i] , BIT[i] = 0;

         for ( ll i = 1 ; i<=n ; ++i ){
              update ( i , arr[i] );
         }

         while ( q-- ) {
             int task;
             scanf ( "%d" , &task );
             /// cout << task << "\n";
             if ( task == 1 ){
                 scanf ( "%d" , &l );
                 printf ( "%d\n" , arr[l+1]);
                 update ( l+1 , -arr[l+1] );
                 arr[l+1] = 0;
             }
             else if ( task == 2 ){
                 scanf ( "%d%d" , &l , &v );
                 arr[l+1]+=v;
                 update ( l+1 , v );
             }
             else {
                 scanf ( "%d%d" , &l , &r );
                 int x =  query ( r + 1 ) - query ( l );
                 printf ( "%d\n" , x );
             }
         }
   }


}



/*
Explanation:





----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/

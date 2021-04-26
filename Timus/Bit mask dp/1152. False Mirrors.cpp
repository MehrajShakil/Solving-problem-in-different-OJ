#include<bits/stdc++.h>
using namespace std;

const int N = 20;
int dp[1<<N];
int n;
int arr[N+5];
int sum = 0;

int recur ( int ind , int mask ) {

   if ( mask == (1<<n) - 1 or ind == n ) {
    return ( mask == (1<<n)-1 ? 0 : 1e9 );
   }

   int &ret = dp[mask];

   if ( ~ret ) return ret;

   ret = 1e9;

   for ( int i = ind ; i < n ; ++i ) {

      if ( (mask&(1<<i)) == 0 ) {

          int cnt = 3;
          int j = i;
          int cost = 0;
          int temp = 0;

          while ( cnt-- ){
          if ( (mask&(1<<j)) == 0 ) {
            cost+=arr[j];
            temp|=(1<<j++);
          }
          if ( j == n ) j = 0;
          }

          sum-=cost;
          ret = min ( ret , sum + recur ( 0 , mask|temp ) );
          sum+=cost;
      }
      ret = min ( ret , recur ( i + 1 , mask ) );
   }

   return ret;
}

int main()
{
   /// scanf ("");

   ios::sync_with_stdio(false);
   cin.tie(NULL);

   memset ( dp , -1 , sizeof dp );

   cin >> n;

   for ( int i = 0 ; i < n ; ++i ) cin >> arr[i] , sum+=arr[i];
   arr[n] = arr[0];
   arr[n+1] = arr[1];

   cout << recur ( 0 , 0 ) << "\n";


}

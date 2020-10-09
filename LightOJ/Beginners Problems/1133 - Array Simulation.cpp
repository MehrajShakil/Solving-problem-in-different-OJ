///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME
///   ALLAH save us from COVID-19.Amin.

///   Every soul shall taste death.

///   Tag ::

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>


///  order_of_key return number of elements less than x.
///  find_by_order return index.
using namespace std;

using ll = long long;

int main()
{

  /// MOHAMMAD

   ll t , tc = 0;
   cin >> t;

   while ( t-- ){

        ll n , m;
        cin >> n >> m;
        ll arr[n] , add = 0 , mul = 1 , div = 1 , rev = 0;

        for ( ll i = 0 ; i<n ; ++i ) cin >> arr[i];
        char ch;
        while ( m-- ){
             cin >> ch;
             ll v;
             if ( ch=='S' ){
                cin >> v;
                for ( ll i = 0 ; i<n ; ++i ) arr[i]+=v;
             }
             if ( ch=='M' ) {
                cin >> v;
               for ( ll i = 0 ; i<n ; ++i ) arr[i]*=v;
             }
             if ( ch=='D' ){
                cin >> v;
                for ( ll i = 0 ; i<n ; ++i ) arr[i]/=v;
             }
             if ( ch=='R' ) {
                ll temp[n];
                for ( ll i = 0 ; i<n ; ++i ) {
                    temp[i] = arr[i];
                }
                for ( ll i = 0 ; i<n ; ++i ) {
                    arr[i] = temp[n-i-1];
                }
             }
             if ( ch=='P' ){
                ll x,  y;
                cin >> x >> y;
                swap ( arr[x] , arr[y] );
             }
        }


                cout << "Case " << ++tc << ":\n";
                for ( ll i = 0 ; i<n ; i++ ) cout << arr[i] << " \n"[i==n-1];
   }


}



/*
Explanation:
----------------------------------------------------------------------------------------------------------------
  Alhamdulillah
*/

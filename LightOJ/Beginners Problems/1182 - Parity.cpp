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

        ll n , bit = 0;
        cin >> n;

        for ( ll k = 31 ; ~k ; k-- ){
             if ( (1<<k)&n ) bit++;
        }

        if ( bit&1) cout << "Case " << ++tc << ": odd\n";
        else cout << "Case " << ++tc << ": even\n";
   }


}



/*
Explanation:
----------------------------------------------------------------------------------------------------------------
  Alhamdulillah
*/

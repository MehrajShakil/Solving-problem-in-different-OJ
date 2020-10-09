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
        vector < ll > s;
        ll x;
        cin >> x;
        while ( x ){
            s.push_back(x%10);
            x/=10;
        }

        ll n = s.size();
        bool ans = true;
        for ( ll i = 0 ; i<n/2 ; ++i ){
            if ( s[i]!=s[n-i-1] ) ans = false;
        }
        cout << "Case " << ++tc << ": ";
        if ( ans ) cout << "Yes\n";
        else cout << "No\n";
   }


}



/*
Explanation:





----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/

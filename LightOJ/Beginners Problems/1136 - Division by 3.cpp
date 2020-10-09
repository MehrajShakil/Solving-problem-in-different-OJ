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
        ll a , b;
        cin >> a >> b;
        ll r = b/3;
        r*=2;
        if ( b%3==2 ) r++;
        a--;
        ll l = a/3;
        l*=2;
        if ( a%3==2 ) l++;
        cout << "Case " << ++tc << ": " << r - l << "\n";
   }


}



/*
Explanation:
----------------------------------------------------------------------------------------------------------------
  Alhamdulillah
*/

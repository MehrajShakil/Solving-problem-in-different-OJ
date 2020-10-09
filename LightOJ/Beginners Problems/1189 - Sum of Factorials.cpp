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
   vector < ll > v;
   ll mul = 1;
   v.push_back(1);
   for ( ll i = 1 ; i<=20 ; ++i ){
        mul*=i;
        v.push_back(mul);
   }

   while ( t-- ){
        ll n;
        cin >> n;
        stack < ll > ans;

        for ( ll i = v.size() - 1 ; ~i ; i-- ){
             if ( n>=v[i] ){
                 n-=v[i];
                 ans.push(i);
             }
        }



        cout << "Case " << ++tc << ": ";
        ll f = 0;
        while ( ans.size()>1 and n==0 ){
               cout << ans.top() << "!+";
               ans.pop();
        }
        if ( n==0 ) cout << ans.top() <<"!\n";
       if ( n>0 ) {
                cout << "impossible\n";
       }
   }
}



/*
Explanation:
----------------------------------------------------------------------------------------------------------------
  Alhamdulillah
*/

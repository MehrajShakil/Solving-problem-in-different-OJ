///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME
///   ALLAH save us from COVID-19.Amin.

///   Every soul shall taste death.

///   Tag ::

#include<bits/stdc++.h>
using namespace std;

#define ld        double

using ll = long long;

//***********************************************  The END **********************************************************************************************************************************
const ll N     = 1e5+1;
const ll INF   = 1e15;
const ll limit = (1LL<<64) - 1;
const ld EPS   = 1e-8;



int main()
{

  /// MOHAMMAD
  // AE;

   int t , tc = 0;
   scanf ( "%d" , &t );
   while ( t-- ) {
       ld x , y , c;
       scanf ( "%lf%lf%lf" , &x , &y , &c );
       ld lo = 0.0 , hi = min ( x , y ) , d;

       while ( hi - lo > EPS ){

            d = (hi+lo)/2.00;
            ld h1 = sqrt ( (x*x) - (d*d) );
            ld h2 = sqrt ( (y*y) - (d*d) );
            ld h = h1*h2/(h1+h2);
            if ( fabs ( h - c ) <= EPS ) break;
            else if ( h>c ) lo = d;
            else if ( h<c ) hi = d;
       }

       /// dbg ( lo  );

       printf ( "Case %d: %.8lf\n" , ++tc , d );
   }
   return 0;
}



/*
Explanation:





----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/

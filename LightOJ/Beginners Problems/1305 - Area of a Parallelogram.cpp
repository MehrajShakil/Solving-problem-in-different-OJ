
///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME
///   ALLAH save us from COVID-19.Amin.

///   Every soul shall taste death.

///   Tag ::

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = double;

const ll MAXN = 1e7+1;
const ll INF = 1e18;
const ll limit = (1LL<<64) - 1;
const ld EPS   = 1e-8;


int main()
{


   ll t , tc = 0;
   cin >> t;

   while ( t-- ){
       ll ax , ay , bx , by , cx , cy , dx , dy;
       cin >> ax >> ay >> bx >> by >> cx >> cy;
       dy = ay + (cy-by);
       dx = cx -  (bx - ax );

       ll tri1 = abs(ax * ( by - dy ) + bx * ( dy - ay ) + dx * ( ay - by ));
       ll tri2 = abs(cx * ( by - dy ) + bx * ( dy - cy ) + dx * ( cy - by ));

      // cout << tri1 << " " << tri2 << "\n";



       cout << "Case " << ++tc << ": " << dx << " " << dy << " " << (tri1+tri2)/2 << "\n";
   }


}



/*
Explanation:





----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/

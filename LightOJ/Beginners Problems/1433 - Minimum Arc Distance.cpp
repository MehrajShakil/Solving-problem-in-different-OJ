
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

const ll MAXN = 1e7+1;
const ll INF = 1e18;
const ll limit = (1LL<<64) - 1;
const ld EPS   = 1e-8;


int main()
{
   AE;
   ll t , tc = 0;
   cin >> t;

   while ( t-- ){

       ld ox , oy , ax , ay , bx , by;
       cin >> ox >> oy >> ax >> ay >> bx >> by;

       ld r = sqrt ( ( (ox - ax)*(ox - ax)) + (( oy - ay ) *( oy  - ay )));
       ld c = sqrt ( ( (bx - ax)*(bx - ax)) + (( by - ay ) *( by  - ay )));

       /// a^2 + b^2 - 2abcos ( C ) = c^2. /// cosine law.

       ld ang = acos( ( (2*(r*r)) - (c*c) )/(2.0*r*r));

       ld ans = ang*r;

       cout << "Case " << ++tc << ": " << ans << "\n";



   }


}



/*
Explanation:





----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/

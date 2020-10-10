
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
         ll n , m, x;
         cin >> n >> m;
         deque < ll > dq;
         cout << "Case " << ++tc << ":\n";
         while ( m-- ){
             string s;
             cin >> s;
             if ( s== "pushLeft" ){
                cin >> x;
                if ( dq.size()==n ) {
                  cout << "The queue is full\n";
                  continue;
                }
                cout << "Pushed in left: " << x << "\n";
                dq.push_front(x);
             }
             if ( s== "pushRight" ){
                cin >> x;
                if ( dq.size()==n ) {
                  cout << "The queue is full\n";
                  continue;
                }
                cout << "Pushed in right: " << x << "\n";
                dq.push_back(x);
             }
             if ( s== "popLeft" ){
                if ( dq.size()==0 ) {
                  cout << "The queue is empty\n";
                  continue;
                }
                cout << "Popped from left: " << dq.front() << "\n";
                dq.pop_front();
             }
             if ( s== "popRight" ){
                if ( dq.size()==0 ) {
                  cout << "The queue is empty\n";
                  continue;
                }
                cout << "Popped from right: " << dq.back() << "\n";
                dq.pop_back();
             }
         }
   }


}



/*
Explanation:





----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/

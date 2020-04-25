//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
#include<bits/stdc++.h>
#define IOS   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//Sequence Containers : vector,deque,list....
#define vc    vector<char>
#define vi    vector<long long>
#define vs    vector<string>
#define dqi   deque<long long>
#define dqc   deque<char>
#define lii   list<long long>
#define lic   list<char>
#define pb    push_back
#define pf    push_front
#define pff() pop_front()
#define pbb() pop_back()

//Container Adaptors : queue,priority_queue, stack....
#define sti   stack<int>
#define stc   stack<char>

//Associative Containers : map,set....
#define mpll  map<long long ,long long>
#define mpss   map<string,ll>
#define mpi   map<int,int>
#define si    set<long long>
#define sc    set<string>
#define msi   multiset<long long>
#define ull    unsigned long long
#define ll   long long
#define ses   "\n"
#define X     first
#define Y     second
#define boroo  1e18

// Direction array
ll fx[]= {1,-1,0,0};
ll fy[]= {0,0,1,-1};
using namespace std;
//second element sort vector desen...
bool pairCompare2(const std::pair<ll, ll >& firstElem, const std::pair<ll, ll >& secondElem)
{
    return firstElem.second > secondElem.second;

}
// Find max element of map with key.........
#define jokhonDorkrHobe map<int,int>::iterator best=max_element(mp.begin(),mp.end(),[] (const std::pair<char,ll>& a, const std::pair<char,ll>& b)->bool{ return a.second < b.second; } );

//main function is here........
int main()
{
    string s;
    cin>>s;
    ll ans=0,flag=1,point=0;
    for(ll i=3; i<s.size(); i++)
    {
        if(s[i-3]=='b' && s[i-2]=='e' && s[i-1]=='a' && s[i]=='r')
        {
            ans+=i-2;
            flag=0;
            point = i-2;
        }
        else if(flag==0)
        {
            ans+=point;
        }
    }
    cout<<ans;
}







//Alhamdulillah

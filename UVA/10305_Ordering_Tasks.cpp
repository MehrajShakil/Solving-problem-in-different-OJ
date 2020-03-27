
#include<bits/stdc++.h>
using namespace std;
using ll =  long long;
int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}
int main(){
ll n,m;
while(cin>>n>>m && n!=0 || m!=0){
         visited.clear();
         visited.assign(n+1, 0);
         adj.resize(n+1);
 ll u ,v ;
 while(m--){
 cin>>u>>v;
 adj[u].push_back(v);
 }
for(ll i=1;i<=n;i++){
if(!visited[i])dfs(i);
}
reverse(ans.begin(),ans.end());
for(ll i=0;i<n;i++){
                cout<<ans[i];
                if(i!=n)cout<<' ';
}
cout<<'\n';
}
}

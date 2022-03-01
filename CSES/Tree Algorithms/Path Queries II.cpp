#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5+10;

vector<ll> e[N],parent,depth,heavy,head,pos;
ll cur_pos = 1;
ll tr[N<<2];
ll arr[N];
ll n;
ll brr[N];

/// select the specialChild.
int dfs( int node , int par = -1 ){
    int Size = 1;
    int max_c_size = 0;
    parent[node] = par;
    for ( auto child : e[node] ) {
        if(par==child) continue;
        depth[child] = depth[node] + 1;
        int isSpecialChild = dfs(child,node);
        Size+=isSpecialChild;
        if(isSpecialChild>max_c_size){
            max_c_size = isSpecialChild;
            heavy[node] = child; /// This one is a special child. because it's subtree size is greater than others.
        }
     }
     return Size;
}


/// divide into chain.
void decompose(int node, int h){
    head[node] = h;
    pos[node] = cur_pos++;
    if(heavy[node]!=-1) {
        decompose(heavy[node],h);
    }
    for(auto child:e[node]){
        if(child!=parent[node] and child!=heavy[node]){
           decompose(child,child);
        }
    }
}

void build(int node, int l,int r){
    if(l==r){
        tr[node] = brr[l];
    }
    else{
        int mid = (l+r)>>1;
        int lc = node*2;
        int rc = lc+1;

        build(lc,l,mid);
        build(rc,mid+1,r);

        tr[node] = max(tr[lc],tr[rc]);
    }
}

void update(int node, int l, int r, int pos){
     if(l==r) {
        tr[node] = brr[l];
     }
     else{
        int mid = (l+r)>>1;
        int lc = node*2;
        int rc = node*2+1;

        if(pos<=mid)update(lc,l,mid,pos);
        else update(rc,mid+1,r,pos);
        tr[node] = max(tr[lc],tr[rc]);
     }
}

int query(int node, int l, int r, int ql, int qr){
    if(l>qr or r<ql) return 0;
    if(l>=ql and r<=qr ) return tr[node];

    int mid = (l+r)>>1;
    int lc = node*2;
    int rc = node*2+1;

    int bame = query(lc,l,mid,ql,qr);
    int dane = query(rc,mid+1,r,ql,qr);

    return max(bame,dane);
}


/// heavy light query.
ll hldQuery(int u, int v){
   ll res = 0;
   for(; head[u]!=head[v]; v = parent[head[v]]){
       if(depth[head[u]]>depth[head[v]]){
        swap(u,v);
       }
       ll cur_heavy_path_mx = query(1,1,n,pos[head[v]], pos[v]);
       res = max(res,cur_heavy_path_mx);
   }
   if(depth[u]>depth[v]){
    swap(u,v);
   }
   ll last_heavy_path_mx = query(1,1,n,pos[u],pos[v]);
   res = max(res,last_heavy_path_mx);
   return res;
}


/// Initialize all of them.
void init(int node){
  for(int i = 1 ; i<=node; ++i ) {
    e[i].clear();
  }

  parent.resize(node+1);
  depth.resize(node+1);
  heavy.resize(node+1,-1);
  head.resize(node+1);
  pos.resize(node+1);
  cur_pos = 1;
}





int main(){

    ios::sync_with_stdio(0);cin.tie(0);
    int node, m,u,v;
    cin >> n >> m;

    for ( int i = 1 ; i<=n ; ++i ) cin >> arr[i];

    init(n);

    for(int i = 1; i<n; ++i){
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1);
    decompose(1,1);

    for ( int i = 1; i<=n ; ++i ) {
        brr[pos[i]] = arr[i];
    }

    build(1,1,n);

    for ( int i = 1 ; i<=m ; ++i ) {
        ll task,u,x,v;
        cin >> task;
        if(task==1){ /// change.
            cin >> u >> x;
            brr[pos[u]] = x;
            update(1,1,n,pos[u]);
        }
        else{ /// getting.
            cin >> u >> v;
            cout << hldQuery(u,v) << "\n";
        }
    }
}

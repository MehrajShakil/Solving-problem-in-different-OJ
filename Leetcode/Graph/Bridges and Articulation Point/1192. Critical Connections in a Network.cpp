
class Solution {
public:

    vector < vector < int >  > e;
    vector < int > tin , low;
    vector< vector< int > > ans;
    vector < bool > visit;
    
    int timer = 1;
    void dfs ( int u , int par ){
        
        visit[u] = true;
        
        tin[u] = low[u] = timer++;
        
        for ( auto v : e[u] ){
            if ( v==par ) continue;
            if ( visit[v] ){
                /// back-edge.
                low[u] = min ( low[u] , tin[v] );
            }
            else{
                dfs ( v , u );
                low[u] = min ( low[u] , low[v] );
                if ( tin[u]<low[v] ) ans.push_back ( { u , v } );
            }
        }
        
        
        
    }
    
    

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       
        e     = vector < vector < int > > (n);
        tin   = vector < int > (n);
        low   = vector < int > (n);
        visit = vector < bool > ( n,0 );
        for ( int i = 0 ; i<connections.size() ; ++i ){
            int u = connections[i][0];
            int v = connections[i][1];
            e[u].push_back ( v );
            e[v].push_back ( u );
        }
        
        dfs ( 0 , -1 );
        
      return ans;
    }
};

class Solution {
    
    void dfs ( vector<vector<int>>& image , int row , int col , int x , int y ,int source , int newColor ){
        if ( x<0 or x>=row or y<0 or y>=col or image[x][y]!=source ) return;
        
        image[x][y] = newColor;
        
        dfs ( image , row , col , x+1 , y , source , newColor );
        dfs ( image , row , col , x , y+1 , source , newColor );
        dfs ( image , row , col , x-1 , y , source , newColor );
        dfs ( image , row , col , x , y-1 , source , newColor );  
    }
    
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if(newColor==image[sr][sc]) return image;
        
        int row = image.size();
        int col = image[0].size();
        
        int source = image[sr][sc];
        
        dfs ( image , row , col , sr , sc , source , newColor );
        
        return image;
        
        
    }
};

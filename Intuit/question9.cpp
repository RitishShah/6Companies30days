class Solution {
private:
    void ocean(vector<vector<int>> &heights, int row, int col, int prevElement, vector<vector<int>> &vis){
        if(row<0 || row>=heights.size() || col<0 || col>=heights[0].size() || vis[row][col] || prevElement > heights[row][col]) return;
        
        vis[row][col] = 1;
        
        ocean(heights,row+1,col,heights[row][col],vis); // down
        ocean(heights,row-1,col,heights[row][col],vis); // top
        ocean(heights,row,col+1,heights[row][col],vis); // right
        ocean(heights,row,col-1,heights[row][col],vis); // left
        
        return;
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        
        if(heights.size() < 1) return ans;
        
        int n = heights.size();   // Row
        int m = heights[0].size(); // Column
        
        vector<vector<int>> pacific(n, vector<int>(m,0));
        vector<vector<int>> atlantic(n, vector<int>(m,0));
        
        for(int col=0;col<m;col++){
            // top-boundary for pacific ocean
            ocean(heights,0,col,INT_MIN,pacific);
            
            // down-boundary for atlantic ocean
            ocean(heights,n-1,col,INT_MIN,atlantic);
        }
        
        for(int row=0;row<n;row++){
            // left-boundary for pacific ocean
            ocean(heights,row,0,INT_MIN,pacific);
            
            // right-boundary for atlantic ocean
            ocean(heights,row,m-1,INT_MIN,atlantic);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] == 1 && atlantic[i][j] == 1){
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
    }
};

TC = O(4^min(n,m))
SC = O(n*m)
class Solution
{
    private:
    int findArea(vector<vector<int>> &grid, int row, int col, int maxRow, int maxCol){
        if(row<0 || col<0 || row >= maxRow || col >= maxCol || grid[row][col]==0) return 0;
        
        grid[row][col] = 0;
        
        int size = 1;
        for(int r=row-1;r<=row+1;r++){
            for(int c=col-1;c<=col+1;c++){
                if(r != row || c != col){
                    size += findArea(grid,r,c,maxRow,maxCol);
                }
            }
        }
        return size;
    }
    
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int maxArea = INT_MIN;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    int countArea = findArea(grid, i, j, n, m);
                    maxArea = max(maxArea, countArea);
                }
            }
        }
        
        return maxArea;
    }
};

TC = O(8(n*m))
SC = O(1)
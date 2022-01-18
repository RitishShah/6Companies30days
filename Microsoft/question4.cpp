class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int>List;
        int rowStart = 0, rowEnd = r-1, colStart = 0, colEnd = c-1;
    
        while(rowStart <= rowEnd && colStart <= colEnd){
            // rowStart
            for(int col=colStart;col<=colEnd;col++)
            List.push_back(matrix[rowStart][col]);
        
            rowStart++;
        
            //colEnd
            for(int row=rowStart;row<=rowEnd;row++)
            List.push_back(matrix[row][colEnd]);
        
            colEnd--;
        
            //rowEnd
            // This condition is necessary for (3*5) matrix. Or else 2 extra elements will print
            if(rowStart<=rowEnd){
                for(int col=colEnd;col>=colStart;col--)
                List.push_back(matrix[rowEnd][col]);
                
                rowEnd--;
            }    
        
            //colStart
            // This condition is necessary for (5*3) matrix. Or else 2 extra elements will print
            if(colStart<=colEnd){
                for(int row=rowEnd;row>=rowStart;row--)
                List.push_back(matrix[row][colStart]);
        
                colStart++;
            }
        }
    
        return List;
    }
};

TC = O(r*c)   (r-> Row of grid), (c-> Column of grid)
SC = O(1)
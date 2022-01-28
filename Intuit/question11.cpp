class Solution {
private:
    Node* constructQuad(vector<vector<int>> grid, int rowStart, int rowEnd, int colStart, int colEnd, int length){
        
        int sum = 0;
        for(int i=rowStart;i<rowEnd;i++){
            for(int j=colStart;j<colEnd;j++){
                sum += grid[i][j];
            }
        }
        
        Node*quad;
        // Node(val, isLeaf)
        
        if(sum == 0){
            quad = new Node(false, true);
        }
        
        else if(sum == (length*length)){
            quad = new Node(true, true);
        }
        
        else{
            length = length/2;
            quad = new Node(true, false);
            quad->topLeft = constructQuad(grid, rowStart, rowStart+length, colStart, colStart+length, length);
            quad->topRight = constructQuad(grid, rowStart, rowStart+length, colStart+length, colEnd, length);
            quad->bottomLeft = constructQuad(grid, rowStart+length, rowEnd, colStart, colStart+length, length);
            quad->bottomRight = constructQuad(grid, rowStart+length, rowEnd, colStart+length, colEnd, length);
        }
        return quad;
    }
    
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        Node* ans = constructQuad(grid,0,n,0,n,n);
        return ans;
    }
};

TC = O((n^2)*(4^n)) amortisely = O(4^n)
SC = O(n^2)
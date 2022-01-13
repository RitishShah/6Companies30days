class Solution{
public:
    int isValid(vector<vector<int>> mat){
        
        int n = mat.size(), m = mat[0].size();
        
        unordered_map<string,int> isPresent;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] != 0){
                string rowPresent = "row" + to_string(i) + to_string(mat[i][j]);
                string colPresent = "col" + to_string(j) + to_string(mat[i][j]);
                string boxPresent = "box" + to_string((i/3)*3 + j/3) +  to_string(mat[i][j]);
                
                isPresent[rowPresent]++;
                isPresent[colPresent]++;
                isPresent[boxPresent]++;
                
                if(isPresent[rowPresent] > 1 || isPresent[colPresent] > 1 || isPresent[boxPresent] > 1)
                return 0;
                }
            }
        }
        
        return 1;
    }
};

TC = O(n*m) // I have used unordered_map also, but i'am taking to operations to be done in O(1) for each element.
SC = O(n*m) // As we have used map data structure to store all elements of grid.
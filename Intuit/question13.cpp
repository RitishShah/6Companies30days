class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeroes;
        
        for(int i=0;i<n;i++){
            int zero = 0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j] == 0) zero++;
                else break;
            }
            trailingZeroes.push_back(zero);
        }
        
        int swaps = 0;
        
        for(int i=0;i<n;i++){
            if(trailingZeroes[i] < n-1-i){
                int j=i+1;
                while(j<n && trailingZeroes[j] < n-1-i) j++;
                
                // if last row also doesn't have (n-1-i) zeroes then grid is not valid. 
                if(j == n) return -1;
                
                while(j>i){
                    swap(trailingZeroes[j],trailingZeroes[j-1]);
                    swaps++;
                    j--;
                }
            }
        }
        return swaps;
    }
};

TC = O(n^2)
SC = O(n^2)
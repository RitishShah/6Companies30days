class Solution{
public:
    int lengthOfLongestAP(int A[], int n) {
        if(n <= 2) return n;
        
        vector<unordered_map<int,int>> lengthTable(n);
        int ans = 2;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff = A[j] - A[i];
                
                if(lengthTable[i].find(diff) != lengthTable[i].end()){
                    lengthTable[j][diff] = lengthTable[i][diff] + 1;
                }
                
                else{
                    lengthTable[j][diff] = 2;
                }
                
                ans = max(ans,lengthTable[j][diff]);
            }
        }
        
        return ans;
    }
};

TC = O(n^2)
SC = O(n^2)
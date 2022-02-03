class Solution
{
    private:
    int solve(int i, int j, int n, int m, vector<vector<int>> &t){
        if(i > n || j > m) return 0;
        
        if(t[i][j] != -1) return t[i][j];
        
        if(i==n-1 && j==m-1) return 1;
        
        int down = solve(i+1,j,n,m,t);
        int right = solve(i,j+1,n,m,t);
        
        return t[i][j] = (down + right);
    }
    
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> t(a+1,vector<int>(b+1,-1));
        return solve(0,0,a,b,t);
    }
};

TC = O(n*m)
SC = O(n*m)
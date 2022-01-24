class Solution {
private:
    int solve(vector<int> A, int i, int j, int t[][501]){
        if(i > j) return 0;
        if(i == j) return A[i];
        
        if(t[i][j] != -1) return t[i][j];
        
        // From i+2 to j -> if opponent picks item from start also.
        // From i+1 to j-1 -> if opponent picks item from end.
        int pickFromStart = A[i] + min(solve(A,i+2,j,t), solve(A,i+1,j-1,t));
        
        // From i to j-2 -> if opponent picks item from end also.
        // From i+1 to j-1 -> if opponent picks item from start.
        int pickFromEnd = A[j] + min(solve(A,i,j-2,t), solve(A,i+1,j-1,t));
        
        int maxPick = max(pickFromStart,pickFromEnd);
        return t[i][j] = maxPick;
    }
public:
    int maxCoins(vector<int>&A,int n)
    {
	    int static t[501][501];
	    memset(t,-1,sizeof(t));
	    return solve(A, 0, n-1, t);
    }
};

TC = O(n^2)
SC = O(n^2)
class Solution {
private:
    int solve(vector<int> piles, int i, int j, vector<vector<int>> &t){
        if(i>j) return 0;
        
        if(t[i][j] != -1) return t[i][j];
        
        int takeRight = piles[i] + min(solve(piles,i+2,j,t),solve(piles,i+1,j-1,t));
        int takeLeft = piles[j] + min(solve(piles,i,j-2,t),solve(piles,i+1,j-1,t));
        
        return t[i][j] = max(takeRight,takeLeft);
    }
    
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> t(n+1, vector<int>(n+1,-1));
        int alice = solve(piles,0,n-1,t);
        
        int sum = 0;
        for(int i=0;i<n;i++) sum +=piles[i];
        
        // sum is odd so we divide sum by 2 then if that sum >= then stones of alice then it means that bob has won the game.
        sum/=2;
        
        if(sum < alice) return true;
        else return false;
    }
};

TC = O(n*m)
SC = O(n*m)
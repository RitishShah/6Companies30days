class Solution {
private:
    int solve(int start, int end, int t[][201]){
        if(start >= end) return 0;
        
        if(t[start][end] != -1) return t[start][end];
        
        int minAmount = INT_MAX;
        
        for(int i=start;i<=end;i++){
            int higher = solve(start,i-1,t);
            int lower = solve(i+1,end,t);
            
            int tempAns = i + max(higher, lower);
            
            minAmount = min(minVal,tempAns);
        }
        return t[start][end] = minAmount;
    }
    
public:
    int getMoneyAmount(int n) {
        int static t[201][201];
        memset(t,-1,sizeof(t));
        return solve(1,n,t);
    }
};

TC = O(n*m)
SC = O(n*m)
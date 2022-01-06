class Solution {
  public:
    int findPosition(int N , int M , int K) {
        if(N==1) return 1;  // If, we have only one child then Mth item will dilievered to him only.
        
        int ans = M%N+K-1;
        
        if(ans == 0) return N;
        
        if(ans==N) return ans;
        
        else return ans%N;
    }
};

TC = O(1)
SC = O(1)
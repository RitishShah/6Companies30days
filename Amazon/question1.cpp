class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        
        int t[K+1][N];
        
        for(int i=0;i<K+1;i++){
            for(int j=0;j<N;j++){
                if(i==0 || j==0) t[i][j] = 0;
            }
        }
        
        for(int i=1;i<K+1;i++){
            
            int imax = INT_MIN;
            
            for(int j=1;j<N;j++){
                
                if(t[i-1][j-1] - A[j-1] > imax){
                    imax = t[i-1][j-1] - A[j-1];
                }
                
                if(imax + A[j] > t[i][j-1]){
                    t[i][j] = imax + A[j];
                }
                
                else{
                    t[i][j] = t[i][j-1];
                }
            }
        }
        
        return t[K][N-1];
    }
};

TC = O(N*k)
SC = O(N*K)
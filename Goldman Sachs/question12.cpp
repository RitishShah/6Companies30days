class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        long ans = 0;
        while(N >= 1){
            ans += N*N;
            N--;
        }
        return ans;
    }
};

TC = O(n)
SC = O(1).

// This problem can be done TC = O(1) by using 1^2 + 2^2 + ... + (n*(n+1)*(2n+1))/6
class Solution{
    int MOD = 1e9+7;
    
    // private:
    // long long solve(long long n, long long r){
    //     if(r == 0) return 1%MOD;
        
    //     if(r == 1) return n%MOD;
        
    //     else if(r%2 == 0) return (solve(n,r/2)%MOD * solve(n,r/2)%MOD)%MOD;
        
    //     else return n*(solve(n,r/2)%MOD * solve(n,r/2)%MOD)%MOD;
    // }
    
    public:
    //You need to complete this fucntion
    
    long long power(long long N, long long R)
    {
        long long ans = 1;
        while(R > 0){
            if(R%2 == 1){
                ans = (ans*N)%MOD;
            }
            
            N = (N*N)%MOD;
            
            R /= 2;
        }
        
        return ans%MOD;
    }

};

TC = O(R)
SC = O(1)
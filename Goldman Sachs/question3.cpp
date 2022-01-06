class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans = 0;
        int start = 0;
        long long p = 1;
        
        for(int end=0;end<n;end++){
            p *= a[end];
            
            while(start<end && p >= k){
                p /= a[start];
                start++;
            }
            
            if(p < k){
                long long len = end-start+1; // This will give total subarrays present btw it.
                ans += len;
            }
        }
        
        return ans;
    }
};

TC = O(n)
SC = O(1)
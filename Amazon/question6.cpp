class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        deque<int> dq;
        
        // Base Case
        if(k > n) return ans;
        
        if(k == n){
            int res = INT_MIN;
            for(int i=0;i<n;i++) res = max(arr[i], res);
            ans.push_back(res);
            return ans;
        }
        
        int i=0, j=0;
        
        while(j<n){
            while(!dq.empty() && arr[j] > dq.back())
            dq.pop_back();
            
            dq.push_back(arr[j]);
            
            if(j-i+1 < k) j++;
            
            else if(j-i+1 == k){
                ans.push_back(dq.front());
                
                if(arr[i] == dq.front()) dq.pop_front();
                
                j++;
                i++;
            }
        }
        return ans;
    }
};

TC = O(n)
SC = O(1)
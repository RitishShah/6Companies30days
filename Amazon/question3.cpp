class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> v, int n, int k) {
        vector<int> maxSize;
        deque<int> dq;
        
        // Base Case
        if(k > n) return maxSize;
        
        int i=0, j=0;
        
        while(j < n){
            while(!dq.empty() && v[j] > dq.back())
            dq.pop_back();
            
            dq.push_back(v[j]);
            
            if(j-i+1 < k) j++;
            
            else if(j-i+1 == k){
                maxSize.push_back(dq.front());
                
                if(v[i] == dq.front()) dq.pop_front();
                
                j++;
                i++;
            }
        }
        
        return maxSize;
    }
};

TC = O(n)
SC = O(n)
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        if(nums.size()%2 == 1) return false; //Because odd length elements can't make every pair
        
        int hash[k] = {0};
        
        for(int i=0;i<nums.size();i++){
            int rem = nums[i]%k;
            hash[rem]++;
        }
        
        for(auto &it : nums){
            int rem = it%k;
            
            if(rem == 0){
                int f = hash[rem];
                if(f%2 != 0) return false;
            }
            
            else if(2*rem == k){
                int f = hash[rem];
                if(f%2 != 0) return false;
            }
            
            // This is the case in which rem and k - rem should be equal.
            else{
                int f = hash[rem];
                int of = hash[k-rem];
                
                if(f != of) return false;
            }
        }
        
        return true;
    }
};

TC = O(n)
SC = O(n)
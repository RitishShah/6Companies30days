class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int ans = 0;   // It carry length of subarray.
        int res = INT_MAX;
        int j = 0;        // It act as second pointer.
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            ans++;
            
            while(sum >= target){
                res = min(res,ans);
                ans--;
                sum -= nums[j];
                j++;
            }
        }
        
        if(res == INT_MAX) return 0;
        
        else return res;
    }
};

TC = O(n)
SC = O(1)
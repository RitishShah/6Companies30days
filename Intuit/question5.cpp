class Solution {
private:
    bool minAllocation(int sum, int m, vector<int> nums){
        int tempSum = 0;
        int split = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > sum) return false;  // If single element is greater than sum then we can't spilt it.
            
            if(tempSum+nums[i] <= sum){
                tempSum += nums[i];
            }
            
            else if(tempSum+nums[i] > sum){
                tempSum = nums[i];
                split++;
            }       
        }
        
        // if split exceeds m than it means that count of subarrays are exceeding for making sum.
        if(split > m) return false;
        else return true;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        int res = -1;
        int sum = 0;
        int Max = INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            Max = max(Max,nums[i]);
        }
        
        if(m == nums.size()) return Max;
        
        int low = Max;
        int high = sum;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(minAllocation(mid,m,nums)){
                res = mid;
                high = mid-1;
            }
            
            else{
                low = mid+1;
            }
        }
        return res;
    }
};

TC = O(nlogn)
SC = O(1)
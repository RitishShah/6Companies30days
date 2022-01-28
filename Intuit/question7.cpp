class Solution {
private:
    bool isDistribute(vector<int> nums, int weightCapacity, int days){
        int tempDay = 1;
        int tempCapacity = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+tempCapacity > weightCapacity){
                tempDay++;
                tempCapacity = nums[i];
            }
            
            else{
                tempCapacity += nums[i];
            }
        }
        
        if(tempDay > days) return false;
        else return true;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int sum = 0;
        int Max = INT_MIN;
        for(auto &it : weights){
            sum += it;
            Max = max(Max,it);
        }
        
        int res = -1;
        
        int low = Max;
        int high = sum;  // We know that elements before Max will not be able to give ans.
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(isDistribute(weights,mid,days)){
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
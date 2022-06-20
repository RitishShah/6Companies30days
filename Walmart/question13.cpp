class Solution {
public:
    // It will sort vector in decreasing order.
    struct comparator{
        bool operator() (string s1, string s2){
            // if s1 is greater than s2 then it doesn't requires swap.
            if(s1.size() > s2.size()) return true;
            
            // if s1 is smaller than s2 then it require swap.
            else if(s1.size() < s2.size()) return false;
            
            // if s1 == s2 then we'll iterate each index of both strings to find greater string.
            else{
                for(int i=0;i<s1.size();i++){
                    // No Swap
                    if(s1[i]-'0' > s2[i]-'0') return true;
                    
                    // Swap
                    else if(s1[i]-'0' < s2[i]-'0') return false;
                }
                // if both strings are same then if we do swap or not, doesn't matter.
                return false;
            }
        }
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end(), comparator());
        
        for(auto &it : nums) cout<<it<<" ";
        
        return nums[k-1];
    }
};

TC = O(nlogn)
SC = O(1)

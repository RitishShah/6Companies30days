class Solution {
private:
    bool findingK(vector<int> piles, int k, int h){
        int hours = 0;
        for(int i=0;i<piles.size();i++){
            int hr = piles[i]/k;
            hours += hr;
            if(piles[i]%k != 0) hours++;
        }
        
        if(hours <= h) return true;
        else return false;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int Max = INT_MIN;
        for(int i=0;i<n;i++){
            Max = max(Max,piles[i]);
        }
        
        // Range of finding the value of (k) which is speed of koko to eat bananas per hour.
        int low = 1;
        int high = Max;
        
        int res = -1;
        
        while(low<=high){
            int mid = low + (high-low)/2;  // This is our k value.
            
            if(findingK(piles,mid,h)){
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
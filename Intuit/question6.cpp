class Solution {
private:
    int firstHalf(MountainArray arr, int start, int end, int target){
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(arr.get(mid) == target) return mid;
            
            else if(arr.get(mid) > target) end = mid-1;
            
            else if(arr.get(mid) < target) start = mid+1;
        }
        return -1;
    }
    
    int secondHalf(MountainArray arr, int start, int end, int target){
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(arr.get(mid) == target) return mid;
            
            else if(arr.get(mid) > target) start = mid+1;
            
            else if(arr.get(mid) < target) end = mid-1;
        }
        return -1;
    }
    
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int low = 0;
        int high = n-1;
        // int index = -1;
        int peak = 0;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            int element = arr.get(mid);
                
            if(element > arr.get(mid+1) && element > arr.get(mid-1)){
                    peak = mid;
                    break;
            }
                
            else if(element < arr.get(mid+1)) low = mid+1;
                
            else if(element < arr.get(mid-1)) high = mid-1;

        }
        
        int start = 0;
        
        int mountainIndex = firstHalf(arr,start,peak,target);
        
        if(mountainIndex != -1) return mountainIndex;
        
        start = peak;
        int end = n-1;
        
        int mountainIndex2 = secondHalf(arr,start,end,target);
        
        if(mountainIndex2 != -1) return mountainIndex2;
        
        else return -1;
    }
};

TC = O(nlogn)
SC = O(1)
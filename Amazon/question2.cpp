class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size() < 3) return 0;
        
        int n = arr.size();
        
        int ans = 0;
        int i=1, j=0;
        
        while(i<=n-2){
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                int count = 1;
                j=i;
                
                while(j>0 && arr[j] > arr[j-1]){
                    j--;
                    count++;
                }
                
                while(i<n-1 && arr[i] > arr[i+1]){
                    i++;
                    count++;
                }
                
                ans = max(ans, count);
            }
            
            else i++;
        }
        
        return ans;
    }
};

TC = O(n)
SC = O(1)
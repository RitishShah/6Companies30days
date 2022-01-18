class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> ans;
        if(arr.size() < 4) return ans;
        
        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int tempTarget = k - (arr[i]+arr[j]);
                int front = j+1;
                int back = n-1;
                
                while(front < back){
                    int remainingTarget = arr[front] + arr[back];
                    
                    if(tempTarget < remainingTarget) back--;
                    
                    else if(tempTarget > remainingTarget) front++;
                    
                    else{
                        vector<int> quadrupals(4,0);
                        quadrupals[0] = arr[i];
                        quadrupals[1] = arr[j];
                        quadrupals[2] = arr[front];
                        quadrupals[3] = arr[back];
                        
                        ans.push_back(quadrupals);
                        
                        // Check for duplicates after front.
                        while(front < back && arr[front] == quadrupals[2]) front++;
                        
                        // Check for duplicates before back.
                        while(front < back && arr[back] == quadrupals[3]) back--;
                    }
                }
                while(j+1<n && arr[j] == arr[j+1]) j++;
            }
            while(i+1<n && arr[i] == arr[i+1]) i++;
        }
        return ans;
    }
};

TC = O(N^3)
SC = O(1)
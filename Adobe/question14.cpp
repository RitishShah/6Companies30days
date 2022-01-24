class Solution{
    public:
    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
        
        int minElement, maxElement;
        
        int maxVal = INT_MIN;
        int minVal = INT_MAX;
        int minRange = INT_MAX;
        for(int i=0;i<k;i++){
            minHeap.push({a[i][0],{i,0}});
            maxVal = max(maxVal,a[i][0]);
        }
        
        while(true){
            pair<int,pair<int,int>> temp = minHeap.top();
            minHeap.pop();
            
            int minVal = temp.first;
            
            if(minRange > maxVal-minVal){
                minRange = maxVal-minVal;
                minElement = minVal;
                maxElement = maxVal;
            }
            
            int i = temp.second.first;  // kth list
            int j = temp.second.second; // index of element
            
            if(j == n-1) break;
            
            minHeap.push({a[i][j+1],{i,j+1}});
            
            if(maxVal < a[i][j+1]) maxVal = a[i][j+1];
            
         }
         
         return make_pair(minElement,maxElement);
    }
};

TC = O(n*k*logk)
SC = O(k)
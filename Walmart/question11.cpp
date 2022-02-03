class Solution {
    int MOD = 1e9+7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;  // (speed)
        
        vector<pair<int,int>> ans;
        
        for(int i=0;i<n;i++){
            ans.push_back({efficiency[i],speed[i]});
        }
        
        sort(ans.begin(),ans.end());
        
        for(auto it : ans){
            cout<<it.first<<" ";
        }
        cout<<endl;
        for(auto it : ans){
            cout<<it.second<<" ";
        }
        
        long long sum = 0;
        long long res = INT_MIN;
        long long performance = 0;
        
        for(int i=n-1;i>=0;i--){
            sum += ans[i].second;
            minHeap.push(ans[i].second);
            
            if(minHeap.size() > k){
                sum -= minHeap.top();
                minHeap.pop();
            }
            
            performance = sum * ans[i].first;
            res = max(res,performance);
        }
        
        return res%MOD;
    }
};

TC = O(nlogk)
SC = O(k)
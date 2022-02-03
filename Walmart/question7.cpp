class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        stack<int> st;
        
        for(int i=N-1;i>=0;i--){
            if(st.size() == 3) break;
            
            while(!st.empty() && st.top() <= arr[i]) st.pop();
            
            st.push(arr[i]);
        }
        
        vector<int> ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        if(ans.size() == 3) return ans;
        
        else return {};
    }
};

TC = O(N)
SC = O(N)
class Solution {
  private:
    int findLIS(vector<int> tempA){
        if(tempA.size() == 0) return 0; // If tempA is empty then return 0.
        vector<int> ans;
        ans.push_back(tempA[0]);
        for(int i=1;i<tempA.size();i++){
            if(tempA[i] > ans.back()) ans.push_back(tempA[i]);
            
            else{
                int idx = lower_bound(ans.begin(),ans.end(),tempA[i])-ans.begin();
                ans[idx] = tempA[i];
            }
        }
        
        return ans.size();
    }
    
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        // Base Case
        if(N == M){
            int z=N;
            for(int i=0;i<N;i++){
                if(A[i] == B[i]) z--;
            }
            if(z==0) return 0;
        }
        
        set<int> s;
        for(int i=0;i<M;i++) s.insert(B[i]);
        
        vector<int> tempA;
        for(int i=0;i<N;i++){
            if(s.find(A[i]) != s.end()) tempA.push_back(A[i]);
        }
        
        int lis = findLIS(tempA);
        
        int insertion = N - lis;
        int deletion = M - lis;
        
        return insertion + deletion;
    }
};

TC = O(nlogn)
SC = O(n)
class Solution
{
    private:
    void solve(string str, string &ans, int n, int k, int idx){
        if(k == 0) return;
        
        char maxChar = str[idx];
        for(int i=idx+1;i<n;i++){
            if(maxChar < str[i]) maxChar = str[i];
        }
        
        if(maxChar != str[idx]) k--;
        
        for(int i=n-1;i>=idx;i--){
            if(str[i] == maxChar){
                swap(str[i], str[idx]);
                if(ans < str) ans = str;
                solve(str,ans,n,k,idx+1);
                swap(str[i],str[idx]);
            }
        }
    }
    
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        int n = str.size();
        if(n == 1) return str;
        string ans;
        solve(str,ans,n,k,0);
        return ans;
    }
};

TC = O(n)
SC = O(1)
ASC = O(n)
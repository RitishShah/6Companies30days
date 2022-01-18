class Solution
{
    private:
    void solve(int a[], int N, int idx, string output, vector<string> &ans, unordered_map<int,string> &options){
        if(idx >= N){
            ans.push_back(output);
            return;
        }
        
        string letters = options[a[idx]];
        
        for(int i=0;i<letters.size();i++){
            solve(a, N, idx+1, output+letters[i], ans, options);
        }
    }
    
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        if(N == 0) return {};
        
        vector<string> ans;
        unordered_map<int,string>options;
        
        options[2] = "abc";
        options[3] = "def";
        options[4] = "ghi";
        options[5] = "jkl";
        options[6] = "mno";
        options[7] = "pqrs";
        options[8] = "tuv";
        options[9] = "wxyz";
        
        solve(a, N, 0, "", ans, options);
        
        return ans;
    }
};

TC = O(n*4^n)
SC = O(n)
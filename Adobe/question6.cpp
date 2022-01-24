class Solution
{
    private:
    void solve(int open, int close, string s, vector<string> &ans){
        if(!open && !close){
            ans.push_back(s);
            return;
        }
        
        else if(open == close){
            // open--;
            // s.push_back('(');
            solve(open-1, close, s+'(', ans);
        }
        
// This is the case where all open brackets are used then we are only left with close brackets.
        else if(!open){
            s.push_back(')');
            close--;
            solve(open, close, s, ans);
        }
        
        else if(close > open){
            open--;
            s.push_back('(');
            solve(open, close, s, ans);
            open++;
            close--;
            s.pop_back();
            s.push_back(')');
            solve(open, close, s, ans);
        }
    }
    
    public:
    vector<string> AllParenthesis(int n) 
    {
        if(n==0) return {};
        if(n==1) return {"()"};
        
        int open = n, close = n;
        vector<string> ans;
        string s = "";
        
        solve(open, close, s, ans);
        return ans;
    }
};

TC = O(2^n)
SC = O(1)
ASC = O(n)
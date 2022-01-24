class Solution{
    public:
    string amendSentence (string s)
    {
        string ans = "";
        int n = s.size();

        for(int i=0;i<n;i++){
            if(i == 0 && isupper(s[i])) ans += tolower(s[i]);
            
            else if(isupper(s[i])){
                ans += " ";
                ans += tolower(s[i]);
            }
            
            else ans += s[i];
        }
        
        return ans;
    }
};

TC = O(n)
SC = O(1)
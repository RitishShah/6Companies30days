class Solution{
    public:
    string colName (long long int n)
    {
        string ans;
        
        while(n > 0){
            char c = 'A' + (n-1)%26;
            ans = c + ans;
            n = (n-1)/26;
        }
        
        return ans;
    }
};

TC = O(n)
SC = O(1)
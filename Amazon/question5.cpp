class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        string t = "";
        
        for(int i=0;i<s.size();i++){
            t += s[i];
            vector<string>v;
            set<string>st;
            for(int j=0;j<n;j++){
                int present = contact[j].find(t);
                
                // if (t) is present in contact[j] then it will give value = 0.
                if(present == 0) st.insert(contact[j]);
            }
            
            // If set is not empty then there would be strings which matches the condition.
            if(!st.empty()){
                for(auto &it : st) v.push_back(it);
            }
            
            // If set is empty, it means that no string matches with given condition.
            else{
                v.push_back("0");
            }
            
            ans.push_back(v);
        }
        
        return ans;
    }
};

TC = O(s*n*contact[i])
SC = O(s*contact[i]) As we know, We are storing the strings from contact associated to running stream of string s.
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& s) {
        vector<vector<string>> ans;
        
        if(s.size()==1){
            ans.push_back(s);
            return ans;
        }
        
        unordered_map<string,vector<string>>mp;
        
        for(auto &it : s){
            string temp = it;
            sort(it.begin(),it.end());
            mp[it].push_back(temp);
        }
        
        for(auto &it : mp) ans.push_back(it.second);
        
        return ans;
    }
};
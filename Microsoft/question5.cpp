class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> ans;
       stack<pair<int,int>> s;
       
       for(int i=0;i<n;i++){
           if(s.empty()) ans.push_back(1);
           
           else if(s.size() > 0 && s.top().first > price[i]) ans.push_back(i-s.top().second);
           
           else if(s.size() > 0 && s.top().first <= price[i]){
               while(s.size() > 0 && s.top().first <= price[i]) s.pop();
               
               if(s.empty()) ans.push_back(i+1); // +1 for 0th index element.
               
               else ans.push_back(i-s.top().second);
           }
           
           s.push({price[i],i});
       }
       
       return ans;
    }
};

TC = O(n)
SC = O(n)
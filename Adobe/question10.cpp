class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string,int> voteList;
        
        for(int i=0;i<n;i++) voteList[arr[i]]++;
        
        vector<string> ans;
        int votes = 0; 
        string contender;
        for(int i=0;i<n;i++){
            if(voteList[arr[i]] > votes){
                votes = voteList[arr[i]];
                contender = arr[i];
            }
            
            // contender who is lexicographically smaller will come first.
            else if(voteList[arr[i]] == votes && contender > arr[i]){
                contender = arr[i];
            }
        }
        
        ans.push_back(contender);
        ans.push_back(to_string(votes));
        return ans;
    }
};

TC = O(n)
SC = O(n)
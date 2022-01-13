class Solution {
	public:
		string FirstNonRepeating(string A){
		    if(A.size()==1) return A;
		    
		    string ans = "";
		    deque<char>dq;
		    int hash[26] = {0};
		    
		    for(auto &it : A){
		        int pos = it - 'a';
		        if(hash[pos] == 0) dq.push_back(it);
		        
		        hash[pos]++;
		        
		        while(!dq.empty() && hash[dq.front() - 'a'] != 1) dq.pop_front();
		        
		        if(dq.empty()) ans += '#';
		        else ans += dq.front();
		    }
		    
		    return ans;
		}

};

TC = O(n*26) // We are using hash-table, so for worst case in which we'll store all 26 alphabets in hash while traversing given string.
SC = O(26) // We'll store 26 alphabets in worst case in hash-table.
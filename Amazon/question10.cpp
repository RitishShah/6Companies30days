class Solution{
public:	
	void matchPairs(char nuts[], char bolts[], int n) {
	    if(n==1 && nuts[0] == bolts[0]) return;
	    
	    set<char> mapping;
	    
	    for(int i=0;i<n;i++) mapping.insert(nuts[i]);
	    
	    int i=0;
	    for(auto &it : mapping){
	        nuts[i] = it;
	        bolts[i] = it;
	        i++;
	    }
	    return;
	}

};

TC = O(nlogn)
SC = O(n)
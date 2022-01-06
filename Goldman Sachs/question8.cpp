class Solution {
	public:
		int CountWays(string str){
		    if(str.size()==0 || str[0]=='0') return 0;
		    if(str.size()==1) return 1;
		    
		    int mod = 1e9+7;
		    
		    int tillPrev = 1;
		    int tillPrevOfPrev = 1;
		    
		    for(int i=1;i<str.size();i++){
		        int oneDigit = str[i]-'0';
		        int twoDigit = (str[i-1]-'0')*10 + oneDigit;
		        
		        int currCount = 0;
		        
		        if(oneDigit > 0) currCount += tillPrev%mod;
		        if(twoDigit >= 10 && twoDigit <= 26) currCount += tillPrevOfPrev%mod;
		        
		        tillPrevOfPrev = tillPrev;
		        tillPrev = currCount;
		    }
		    
		    return tillPrev%mod;
		}

};

TC = O(n)
SC = O(1)
ull getNthUglyNo(int n) {
	    ull dp[n+1];
	    
	    dp[1] = 1;
	    
	    ull ptr2 = 1;
	    ull ptr3 = 1;
	    ull ptr5 = 1;
	    
	    for(int i=2;i<n+1;i++){
	        ull f2 = 2*dp[ptr2];
	        ull f3 = 3*dp[ptr3];
	        ull f5 = 5*dp[ptr5];
	        
	        ull Min = min(f2,min(f3,f5));
	        dp[i] = Min;
	        
	        if(Min == f2) ptr2++;
	        
	        if(Min == f3) ptr3++;
	        
	        if(Min == f5) ptr5++;
	    }
	    
	    return dp[n];
	}
};

TC = O(n)
SC = O(n)
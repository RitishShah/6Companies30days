public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>> graph(N);
	    vector<int> ans, indegree(N);
	    
	    // Indegree of element = 0, then that element would depend on other elements.
	    
	    for(auto &it : prerequisites){
	        int f = it.first, s = it.second;
	        
	        graph[f].push_back(s);
	        indegree[s]++;
	    }
	    
	    queue<int>q;
	    
	    for(int i=0;i<N;i++) 
	    if(indegree[i] == 0) q.push(i);
	    
	    while(!q.empty()){
	        int lastCourse = q.front();
	        q.pop();
	        ans.push_back(lastCourse);
	        for(auto &it : graph[lastCourse]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    
	    reverse(ans.begin(),ans.end());
	    
	    if(ans.size()==N) return true;
	    
	    else return false;
	}
};

TC = O(N+E)  (E-> NO. of Edge), (N-> NO. of Nodes)
SC = O(N+E)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> ans, indegree(numCourses);
        
        for(auto &it : prerequisites) {
            int f = it[0];
            int s = it[1];
            graph[f].push_back(s);
            indegree[s]++;
        }
        
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            
            for(auto &it : graph[temp]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);  // If there is a course which require 0 prerequisites then we'll take that course.
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        if(ans.size() == numCourses) return ans;   // Ordering will exist if we are able to take every course.
        
        return {};
    }
};

TC = O(n*2)  2 -> it represents n pairs
SC = O(n*2)
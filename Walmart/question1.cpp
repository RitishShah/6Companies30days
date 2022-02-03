class Solution {
private:
    double findPath(vector<vector<pair<int,double>>> graph, int start, int end){
        int n = graph.size();
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
        vector<double> probability(n+1,0);
        
        probability[start] = -1; // Because start would reach to itself with 100% probability.
        pq.push({-1,start});
        
        while(!pq.empty()){
            double prevProbab = pq.top().first;
            int prevNode = pq.top().second;
            pq.pop();
            
            if(prevNode == end) break;
            
            for(auto &it : graph[prevNode]){
                int currNode = it.first;
                double currProbab = it.second;
                
                if(probability[currNode] > prevProbab*currProbab){
                    probability[currNode] = prevProbab*currProbab;
                    pq.push({probability[currNode],currNode});
                }
            }
        }
        return -probability[end];
    }
    
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> graph(n+1);
        
        bool flag = false;
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
            if(edges[i][0]==end || edges[i][1]==end) flag = true;
        }
        
        double go = 0;
        if(flag == false) return go;
        
        return findPath(graph,start,end);
    }
};

TC = O(N+E(logE))
SC = O(N+E)
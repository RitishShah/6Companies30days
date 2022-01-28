class Solution {
private:
    void dfs(int city, vector<vector<int>> adj, vector<bool> &vis){
        vis[city] = 1;
        
        for(auto &it : adj[city]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        
        // Adjacency List
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int provinces = 0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                provinces++;
            }
        }
        return provinces;
    }
};

TC = O(n^2)
SC = O(n^2)
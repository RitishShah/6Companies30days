class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<pair<int,int>> q;
        
        vector<vector<int>> vis(n, vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        
        if(q.size()==0 || q.size()==n*n) return -1;
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        int distance = -1;
        
        while(!q.empty()){
            distance++;
            int size = q.size();
            
            while(size){
                pair<int,int> node = q.front();
                q.pop();
                
                int xDirection = node.first;
                int yDirection = node.second;
                
                for(int i=0;i<4;i++){
                    int x = dx[i] + xDirection;
                    int y = dy[i] + yDirection;
                    
                    if(x<0 || x>=n || y<0 || y>=n || vis[x][y]==1) continue;
                    
                    vis[x][y] = 1;
                    q.push({x,y});
                }
                size--;
            }
        }
        return distance;
    }
};

TC = O(4*(n^2))
SC = O(n^2)
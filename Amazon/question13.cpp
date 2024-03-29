class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int totalOranges=0;
        queue<pair<int,int>> rotten;
        int countRotten=0;
        int minutes = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != 0) totalOranges++;
                if(grid[i][j] == 2) rotten.push({i,j});
            }
        }
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            countRotten += k;
            
            while(k){
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                
                for(int i=0;i<4;i++){
                    int nx = x+dx[i], ny = y+dy[i];
                    
                    if(nx<0 || ny<0 || nx>=n || ny>= m || grid[nx][ny] != 1) continue;
                    
                    grid[nx][ny] = 2;
                    rotten.push({nx,ny});
                }
                k--;
            }
            if(!rotten.empty()) minutes++;
        }
        
        return (countRotten == totalOranges) ? minutes : -1;
    }
};

TC = O(4(n*m)) // We are performing 4 constant steps for n*m grid.
SC = O(n*m)
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1) return 0;
        
        int ans = 0;
        unordered_map<int,int> checkBoomerang; // For storing the distance of boomerang.
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue; // If we can't be able to find distance of same points.
                int x = (points[i][0] - points[j][0])*(points[i][0] - points[j][0]);
                int y = (points[i][1] - points[j][1])*(points[i][1] - points[j][1]);
                int distance = x + y;
                checkBoomerang[distance]++;
            }
        
            for(auto &it : checkBoomerang){
                int totalBoomerangs = it.second;  // If it.second is 2 then it means that there are two distances who are equal. So, there would be two possible boomeranges.
                ans += totalBoomerangs*(totalBoomerangs-1); // for permutations formed here.
            }
            checkBoomerang.clear(); // It's important to clear the map for next iteration to check that if boomeranges are available for different value of i or not.
        }
        return ans;
    }
};

TC = O(n^2)
SC = O(1)
class Solution{
public:
    int minSteps(int D){
        int step = 0;
        int sum = 0;
        
        if(D == 0) return 0;
        
        while(sum < D){
            sum += step;
            step++;
        }
        
        while((sum-D)%2 == 1){
            sum += step;
            step++;
        }
        
        return step-1;
    }
};

TC = O(D) D -> This is the value till we move on from 0.
SC = O(1)
// In this problem, order does not matter, so that's why can't take permutation of a particular step to reach Nth stair.

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int N)
    {
        if(N==1) return 1;
        
        if(N%2 == 0) return 1 + countWays(N-1);
        
        return countWays(N-1);
    }
};

TC = O(N)
SC = O(N)
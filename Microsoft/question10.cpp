class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int t[n];
        
        t[0] = arr[0];
        t[1] = max(arr[0],arr[1]);
        
        for(int i=2;i<n;i++){
            t[i] = max(arr[i]+t[i-2],t[i-1]);
        }
        
        return t[n-1];
    }
};

TC = O(n)
SC = O(n)
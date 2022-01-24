class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        vector<int> ans;
        if(n == 1 && arr[n] == s){
            ans.push_back(1);
            ans.push_back(1);
            return ans;
        }
        
        int sum = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            
            if(sum == s){
                ans.push_back(j+1);
                ans.push_back(i+1);
                return ans;
            }
            
            else if(sum > s){
                while(sum > s){
                    sum -= arr[j];
                    j++;
                }
                
                if(sum == s){
                    ans.push_back(j+1);
                    ans.push_back(i+1);
                    return ans;
                }
            }
        }
        return {-1};
    }
};

TC = O(n)
SC = O(1)
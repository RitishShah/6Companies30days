class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int a[n+1] = {0};
        
        int *ans = new int[2];
        
        for(int i=0;i<n;i++){
            int x = arr[i];
            a[x]++;
        }
        
        for(int i=1;i<n+1;i++){
            if(a[i] == 2) ans[0] = i;  // It's given in problem that no. occur twice come first.
            if(a[i] == 0) ans[1] = i;  // no. missing in array comes second.
        }
        
        return ans;
    }
};

TC = O(n)
SC = O(n)
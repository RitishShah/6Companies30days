class Solution{
    int const MOD = 1e9+7;
    #define ll long long
    private:
    ll solve(ll n, ll x, ll val, ll t[][1001]){
        ll check = n - pow(val,x);
        
        if(t[n][val] != -1) return t[n][val];
        
        if(check == 0) return 1;
        
        else if(check < 0) return 0;
        
        else{
            ll checkFurther = solve(check,x,val+1,t)%MOD;
            ll checkAnotherWay = solve(n,x,val+1,t)%MOD;
            
            return t[n][val] = checkFurther + checkAnotherWay;
        }
    }
    
    public:
    ll numOfWays(ll n, ll x)
    {
        ll static t[1001][1001];
        memset(t,-1,sizeof(t));
        
        return solve(n,x,1,t)%MOD;
    }
};

TC = O(n^2)
SC = O(n^2)
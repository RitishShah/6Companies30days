class Solution{   
public:
    string printMinNumberForPattern(string S){
        string ans = "";
        int n = 1;
        stack<int> st;
        
        for(auto &it : S){
            if(it == 'I'){
                st.push(n);
                n++;
                
                while(!st.empty()){
                    ans += to_string(st.top());
                    st.pop();
                }
            }
            
            else{
                st.push(n);
                n++;
            }
        }
        
        st.push(n);
        
        while(!st.empty()){
            ans += to_string(st.top());
            st.pop();
        }
        
        return ans;
    }
};

TC = O(n)
SC = O(n)
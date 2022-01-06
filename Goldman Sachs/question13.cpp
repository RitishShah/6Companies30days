
class Solution{
public:
    string decodedString(string s){
        stack<char> st;
        
        for(int i=0;i<s.size();i++){
            if(s[i] != ']') st.push(s[i]);
            
            else{
                
                string ss = "";
                while(!st.empty() && st.top() != '['){
                    ss = st.top() + ss;
                    st.pop();
                }
                st.pop();
                
                string number = "";
                while(!st.empty() && isdigit(st.top())){
                    number = st.top() + number;
                    st.pop();
                }
                
                int k = stoi(number);
                while(k > 0){
                    for(auto &it : ss) st.push(it);
                    k--;
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

TC = O(n)
SC = O(n)
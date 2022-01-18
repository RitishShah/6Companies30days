class Solution{
    void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &graph){
        vis[node] = 1;
        
        for(auto &it : graph[node]){
            if(!vis[it]){
                dfs(it, vis, st, graph);
            }
        }
        
        st.push(node);
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> graph(K);
        
        for(int i=0;i<N-1;i++){
            string firstWord = dict[i];
            string secondWord = dict[i+1];
            
            int minLen = min(firstWord.size(),secondWord.size());
            for(int j=0;j<minLen;j++){
                char ch1 = firstWord[j];
                char ch2 = secondWord[j];
                
                if(ch1 != ch2){
                    graph[ch1-'a'].push_back(ch2-'a');
                    break;
                }
            }
        }
        
        vector<int> vis(K,0);
        stack<int> st;
        string ans = "";
        for(int i=0;i<K;i++){
            if(!vis[i]){
                dfs(i,vis,st,graph);
            }
        }
        
        while(!st.empty()){
            char ch = st.top() + 'a';
            ans += ch;
            st.pop();
        }
        return ans;
    }
};

TC = O(N*S + E)    (S -> length of string present in array)
SC = O(N)
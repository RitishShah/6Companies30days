vector<string> generate(int N)
{
    vector<string> ans;
    string s = "";
    
    for(int i=1;i<=N;i++){
        int j=i;
        while(j){
            int temp = j%2;
            s = to_string(temp) + s;
            j /= 2;
        }
        ans.push_back(s);
        s="";
    }
    return ans;
}

TC = O(n)
SC = O(1)
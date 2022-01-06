string encode(string src)
{     
    string s = "";
    int count = 1;
    for(int i=1;i<src.size();i++){
        if(src[i] == src[i-1]) count++;
        
        else{
            s.push_back(src[i-1]);
            s.append(to_string(count));
            count = 1;
        }
    }
    
    s.push_back(src[src.size()-1]);
    s.append(to_string(count));
    
    return s;
}     
 
TC = O(n)
SC = O(1)
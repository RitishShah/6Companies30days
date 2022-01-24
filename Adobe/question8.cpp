class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int ans = 0;
        
        bool minusPresent = false;
        
        int i=0;
        while(i < str.size()){
            if(str[i] == '-'){
                minusPresent = true;
                i++;
            }
            int integerValue = str[i]-'0';
                continue;
            // we only want integers from 0-9 Not alphabets.
            if(integerValue <= 9 && integerValue >= 0){
                ans = ans*10 + integerValue;
            }
            else return -1;
            i++;
        }
        
        return minusPresent ? ans*-1 : ans;
    }
};

TC = O(n)
SC = O(1)
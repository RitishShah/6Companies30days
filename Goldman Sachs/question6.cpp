class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        if(s1+s2 == s2+s1){
            int GCD = gcd(s1.size(),s2.size());
            string s = s1.substr(0,GCD);
            return s;
        }
        
        else return "";
    }
};

TC = O(log(min size of s1 ans s2));
SC = O(gcd);
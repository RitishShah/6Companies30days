class Solution{
  public:
    string nextPalin(string s) {
        int n = s.size();
        if(n <= 3) return "-1";
        string half = s.substr(0,n/2);
        if(next_permutation(half.begin(), half.end()) == true){
            string ans = half;
            if(n&1 == 1) ans += s[n/2];
            reverse(half.begin(),half.end());
            ans += half;
            return ans;
        }
        return "-1";
    }
};

TC = O(n)
SC = O(1)
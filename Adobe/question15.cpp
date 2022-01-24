#include<bits/stdc++.h>
using namespace std;

string solve(string s, string t)
{
    int n = max(s.size(),t.size());
    for(int i=0;i<n;i++)
    {
        int sChar = s[i];
        int tChar = t[i];

        if(sChar == tChar) continue;

        if(sChar > tChar) return t;

        else return s;
    }
}

string findRecent(string s, string t)
{
    if(!s.size() && !t.size()) return "";

    if(!s.size()) return t;

    if(!t.size()) return s;

    return solve(s,t);

}

int main()

{
    string s = "10.1.1.3";
    string t = "10.1.1.9";

    cout<<findRecent(s,t);

    return 0; 
}

TC = O(n)
SC = O(1)
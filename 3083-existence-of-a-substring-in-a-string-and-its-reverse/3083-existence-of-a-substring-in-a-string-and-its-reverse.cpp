class Solution {
public:
    bool isSubstringPresent(string s) {
        int n = s.size();
        if(n<2) return false;
        for(int i=0;i<n-2;i++){
            if(s[i] == s[i+1] || s[i] == s[i+2]) return true;
        }
        if(s[n-1] == s[n-2]) return true;
        return false;
    }
};
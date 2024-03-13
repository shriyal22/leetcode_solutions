class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = t.size();
        int i=0, j=0;
        while(i<s.size()){
            if(j==n-1 && s[i]==t[j]) return 0;

            if(s[i]==t[j]){
                i++;j++;
            } 
            else i++;
        }
        return n-j;
    }
};
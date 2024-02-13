class Solution {
public:
    bool isPalindrome(string s){
        int i=0, j=s.size()-1;
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto s: words){
            if(isPalindrome(s)) return s;
        }
        return "";
    }
};
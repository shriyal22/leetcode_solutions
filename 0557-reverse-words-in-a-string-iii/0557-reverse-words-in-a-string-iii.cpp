class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        for(char ch: s){
            if(ch==' '){
                ans += temp + " ";
                temp = "";
            }
            else temp = ch + temp;
        }
        ans += temp;
        return ans;
    }
};
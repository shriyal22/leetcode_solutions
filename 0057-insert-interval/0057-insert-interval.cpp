class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int len = 0;
        int j=n-1;
        while(j>=0){
            while(s[j] == ' ') j--;
            while(s[j] != ' '){
                len++;
                j--;
            }
            break;
        }
        return len;
    }
};
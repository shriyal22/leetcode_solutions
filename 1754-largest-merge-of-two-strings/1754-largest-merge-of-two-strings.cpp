class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans = "";
        int i=0, j=0;
        int n = word1.size(), m = word2.size();
        while(i<n && j<m){
            if(word1[i] == word2[j]){
                if(word1.substr(i+1) > word2.substr(j+1)) ans+= word1[i++];
                else ans += word2[j++];
            }
            else if(word1[i] > word2[j]){
                ans += word1[i++];
            } else ans+= word2[j++];
        }
        while(i<n) ans += word1[i++];
        while(j<m) ans += word2[j++];        

        return ans;
    }
};
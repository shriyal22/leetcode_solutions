class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int i = 0, j = n-1;
        int score = 0, finalScore = 0;
        while(i<=j){
            if(tokens[i] <= power){
                power -= tokens[i];
                score++;
                finalScore = max(score, finalScore);
                i++;
            }
            else if(score > 0){
                power += tokens[j];
                score--;
                j--;
            } else break;
            
        }
        return finalScore;
    }
};
class Solution {
public:
    bool check(string s, string r, unordered_map<char, int> &mp){
        if(s==r) return true;
        int n = min(s.size(), r.size()); 
        for(int i=0;i<n;i++){
            if(mp[s[i]] > mp[r[i]]) return false;
            if(mp[s[i]] < mp[r[i]]) return true;
        }
        if(s.size() > r.size()) return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for(int i=0;i<order.size();i++) mp[order[i]] = i;
        
        for(int i=1;i<words.size();i++){
           if(!check(words[i-1], words[i], mp)) return false;
        }
        return true;
    }
};
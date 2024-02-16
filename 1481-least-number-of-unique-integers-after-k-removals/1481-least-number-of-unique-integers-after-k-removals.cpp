class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto num: arr) mp[num]++;    

        set<pair<int, int>> st;
        for(auto it:mp) st.insert({it.second, it.first});
        
        int num=0;
        for(auto it: st){
            if(it.first<=k){
                num++;
                k-= it.first;
            }
        }
        return mp.size() - num;
    }
};
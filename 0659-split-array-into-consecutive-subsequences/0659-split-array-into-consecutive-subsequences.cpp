class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> mp;
        for(auto num: nums) mp[num]++;
        map<int, int> req;

        for(int num: nums){
            if(mp[num] == 0) continue;

            if(req[num]>0){
                req[num]--;
                mp[num]--;

                req[num+1]++;
            } else if(mp[num] && mp[num+1] && mp[num+2]){
                mp[num]--;
                mp[num+1]--;
                mp[num+2]--;
                req[num+3]++;
            } else return false;
        }
        return true;
    }
};
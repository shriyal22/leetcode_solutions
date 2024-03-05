class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int num: nums) st.insert(num);
        vector<int> v;
        for(int num: st) v.push_back(num);

        int j = 0;
        int ans = n;
        for(int i=0;i<v.size();i++){
            while(j<v.size() && v[j] < v[i] + n) j++;
            int count = j-i;
            ans = min(ans, n-count);
        }
        return ans;
    }
};
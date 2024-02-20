class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n = groupSizes.size();
        for(int i=0;i<n;i++) pq.push({groupSizes[i], i});

        vector<int> temp;
        while(!pq.empty()){
            auto [sz, idx] = pq.top();
            pq.pop();
            temp.push_back(idx);
            if(temp.size() == sz){
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};
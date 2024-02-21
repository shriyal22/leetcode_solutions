class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int day = 0;
        int n = plantTime.size();
        if(n==1) return plantTime[0]+growTime[0];

        priority_queue<pair<int, int>> pq;
        for(int i=0;i<n;i++) pq.push({growTime[i], plantTime[i]});
        
        int count = 0;
        for(int i=0;i<n;i++){
            count += pq.top().second;
            day = max(day, count+pq.top().first);
            pq.pop();
        }
        return day;
    }
};



